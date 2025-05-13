#include "serialcommunication.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

SerialCommunication::SerialCommunication(QSqlDatabase db, QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)), database(db)
{
    // Connect to the serial port signals and slots
    connect(serialPort, &QSerialPort::readyRead, this, &SerialCommunication::readData);
}

SerialCommunication::~SerialCommunication()
{
    // Close port if open and cleanup
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

bool SerialCommunication::openPort(const QString &portName, int baudRate)
{
    // Set up the serial port
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Port opened successfully:" << portName;
        return true;
    } else {
        qDebug() << "Failed to open port:" << portName << serialPort->errorString();
        return false;
    }
}

void SerialCommunication::closePort()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Port closed.";
    }
}

void SerialCommunication::writeData(const QByteArray &data)
{
    if (serialPort->isOpen()) {
        serialPort->write(data);
        qDebug() << "Data sent:" << data;
    } else {
        qDebug() << "Port is not open. Cannot send data.";
    }
}

QByteArray SerialCommunication::readData() {
    static QByteArray buffer;
    buffer += serialPort->readAll();

    while (buffer.contains('\n')) {
        int newlineIndex = buffer.indexOf('\n');
        QByteArray line = buffer.left(newlineIndex).trimmed();
        buffer.remove(0, newlineIndex + 1);

        QString decodedLine = QString::fromUtf8(line).trimmed();
        qDebug() << "Data received from Arduino:" << decodedLine;

        if (decodedLine.startsWith("UID:")) {
            QString uid = decodedLine.mid(4).trimmed().toLower();

            // Query dynamic statuses for this UID
            QMap<QString, int> statusCounts;
            QSqlQuery query(database);
            query.prepare("SELECT STATUT, COUNT(*) FROM PROJET WHERE TRIM(UUID) = :uid GROUP BY STATUT");
            query.bindValue(":uid", uid);

            if (query.exec()) {
                while (query.next()) {
                    QString status = query.value(0).toString().trimmed();
                    int count = query.value(1).toInt();
                    statusCounts[status] = count;
                    qDebug() << "Status:" << status << "Count:" << count;
                }

                if (statusCounts.isEmpty()) {
                    // UID not found
                    writeData("END\n");
                    return QByteArray();
                }

                int delay = 0;
                for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
                    QString keyWithoutAccents = removeAccents(it.key());
                    QString lineToSend = keyWithoutAccents + ": " + QString::number(it.value()) + "\n";
                    QByteArray data = lineToSend.toLocal8Bit(); // ou toUtf8() si tu veux garder UTF-8
                    QTimer::singleShot(delay, this, [this, data]() {
                        writeData(data);
                    });
                    delay += 200;
                }

                QTimer::singleShot(delay, this, [this]() {
                    writeData("END\n");
                });

            } else {
                qDebug() << "Query failed:" << query.lastError().text();
                writeData("Erreur BDD\nEND\n");
            }
        }
    }

    return QByteArray();
}
