#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("adam");
db.setPassword("adam");
if(db.open())
    test=true;


return test;
}
