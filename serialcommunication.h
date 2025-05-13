#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QObject>
#include <QSerialPort>
#include <QSqlDatabase>


class SerialCommunication : public QObject
{
    Q_OBJECT

public:
    explicit SerialCommunication(QSqlDatabase db, QObject *parent = nullptr);
    ~SerialCommunication();

    bool openPort(const QString &portName, int baudRate);
    void closePort();
    void writeData(const QByteArray &data);
    void sendStatusCountsToArduino(const QString &uid);
    void sendDataToArduino(const QString &data);
    QByteArray readData();

private:
    QSerialPort *serialPort;
    QSqlDatabase database;
QString removeAccents(const QString& str) {
    QString normalized = str.normalized(QString::NormalizationForm_D);
    QString result;
    for (QChar c : normalized) {
        if (c.category() != QChar::Mark_NonSpacing)
            result.append(c);
    }
    return result;
}
};

#endif // SERIALCOMMUNICATION_H
