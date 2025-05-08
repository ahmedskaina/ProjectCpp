#include "connexion.h"
#include <QSqlDatabase>

connexion::connexion() {}
bool connexion::createconnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("emna");
    db.setPassword("esprit25");

    if(db.open())
        test=true;
    return test;
}

void connexion::closeconnexion()
{
    db.close();
}
