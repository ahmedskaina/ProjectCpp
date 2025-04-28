#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "gestion_client.h"
#include "connexion.h"
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Tentative de connexion à la base de données
    Connection conn;
    if (!conn.createconnect()) {
        // Récupération et affichage de l'erreur SQL
        QSqlDatabase db = QSqlDatabase::database();
        QString errorMsg = db.lastError().text();
        qDebug() << "Erreur de connexion à la base de données:" << errorMsg;
        QMessageBox::critical(nullptr, QObject::tr("Erreur de connexion"),
                              QObject::tr("La connexion à la base de données a échoué.\nVérifiez la configuration de votre DSN et vos paramètres de connexion.\nErreur : %1").arg(errorMsg),
                              QMessageBox::Ok);
        return 1;
    }

    // Si la connexion réussit, lancement de l'application
    gestion_client w;
    w.show();
    return a.exec();
}
