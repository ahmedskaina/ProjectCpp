#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnexion();//cnx bd
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connexion succsseful.\n""click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::information(nullptr,QObject::tr("database is not open"),QObject::tr("connexion failed.\n""click cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}

