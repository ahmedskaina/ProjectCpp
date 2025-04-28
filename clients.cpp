#include "clients.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDate>

// Constructeur par defoux
clients::clients()
{
    ID_CLIENTS = 0;
    NOM_CLIENTS = "";
    PRENOM_CLIENTS = "";
    ADRESS_CLIENTS = "";
    NUMERO_CLIENTS = 0;
     DATEA = QDate::currentDate();
}

// Constructeur avec paramitre
clients::clients(int id, const QString &nom, const QString &prenom, const QString &adresse, QString numero,QDate da)
{
    ID_CLIENTS = id;
    NOM_CLIENTS = nom;
    PRENOM_CLIENTS = prenom;
    ADRESS_CLIENTS = adresse;
    NUMERO_CLIENTS = numero;
    DATEA = da;
}

// Getters
int clients::get_ID_CLIENTS() const
{
    return ID_CLIENTS;
}

QString clients::get_NOM_CLIENTS() const
{
    return NOM_CLIENTS;
}

QString clients::get_PRENOM_CLIENTS() const
{
    return PRENOM_CLIENTS;
}

QString clients::get_ADRESS_CLIENTS() const
{
    return ADRESS_CLIENTS;
}

QString clients::get_NUMERO_CLIENTS() const
{
    return NUMERO_CLIENTS;
}

// Setters
void clients::set_ID_CLIENTS(int id)
{
    ID_CLIENTS = id;
}

void clients::set_NOM_CLIENTS(const QString &nom)
{
    NOM_CLIENTS = nom;
}

void clients::set_PRENOM_CLIENTS(const QString &prenom)
{
    PRENOM_CLIENTS = prenom;
}

void clients::set_ADRESS_CLIENTS(const QString &adresse)
{
    ADRESS_CLIENTS = adresse;
}

void clients::set_NUMERO_CLIENTS(QString numero)
{
    NUMERO_CLIENTS = numero;
}
QDate clients::  get_DATEA() const
{ return DATEA;}

void clients::set_DATEA(QDate d)
{
    DATEA = d;
}
// Méthode pour ajouter un client dans la table CLIENT
bool clients::Ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID_CLIENTS, NOM_CLIENTS, PRENOM_CLIENTS, ADRESS_CLIENTS, NUMERO_CLIENTS,DATEA) "
                  "VALUES (:ID_CLIENTS, :NOM_CLIENTS, :PRENOM_CLIENTS, :ADRESS_CLIENTS, :NUMERO_CLIENTS, :DATEA)");
    query.bindValue(":ID_CLIENTS", ID_CLIENTS);
    query.bindValue(":NOM_CLIENTS", NOM_CLIENTS);
    query.bindValue(":PRENOM_CLIENTS", PRENOM_CLIENTS);
    query.bindValue(":ADRESS_CLIENTS", ADRESS_CLIENTS);
    query.bindValue(":NUMERO_CLIENTS", NUMERO_CLIENTS);
    query.bindValue(":DATEA", DATEA);

    return query.exec();
}

// Méthode pour modifier un client existant
bool clients::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT "
                  "SET NOM_CLIENTS = :NOM_CLIENTS, "
                  "PRENOM_CLIENTS = :PRENOM_CLIENTS, "
                  "ADRESS_CLIENTS = :ADRESS_CLIENTS, "
                  "NUMERO_CLIENTS = :NUMERO_CLIENTS, "
                  "DATEA = :DATEA "
                  "WHERE ID_CLIENTS = :ID_CLIENTS");

    query.bindValue(":ID_CLIENTS", ID_CLIENTS);
    query.bindValue(":NOM_CLIENTS", NOM_CLIENTS);
    query.bindValue(":PRENOM_CLIENTS", PRENOM_CLIENTS);
    query.bindValue(":ADRESS_CLIENTS", ADRESS_CLIENTS);
    query.bindValue(":NUMERO_CLIENTS", NUMERO_CLIENTS);
    query.bindValue(":DATEA", DATEA);

    return query.exec();
}

// Méthode pour afficher tous les clients
QSqlQueryModel* clients::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT");

    // Noms de colonnes pour l'affichage (facultatif)
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_CLIENTS"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_CLIENTS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CLIENTS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESS_CLIENTS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO_CLIENTS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEA"));

    return model;
}

// Méthode pour supprimer un client via son ID
bool clients::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID_CLIENTS=:id");
    query.bindValue(":id", id);
    return query.exec();
}

// Méthode pour rechercher et charger en mémoire un client via son ID
bool clients::RechercheClientParID(int IDrecherche)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE ID_CLIENTS=:IDrecherche");
    query.bindValue(":IDrecherche", IDrecherche);

    if (!query.exec())
        return false;

    if (!query.first())
        return false;

    // Récupération des indices de colonnes
    int nID      = query.record().indexOf("ID_CLIENTS");
    int nNom     = query.record().indexOf("NOM_CLIENTS");
    int nPrenom  = query.record().indexOf("PRENOM_CLIENTS");
    int nAdress  = query.record().indexOf("ADRESS_CLIENTS");
    int nNumero  = query.record().indexOf("NUMERO_CLIENTS");
    int ndatea = query.record().indexOf("DATEA");
    // Mise à jour des attributs
    ID_CLIENTS     = query.value(nID).toInt();
    NOM_CLIENTS    = query.value(nNom).toString();
    PRENOM_CLIENTS = query.value(nPrenom).toString();
    ADRESS_CLIENTS = query.value(nAdress).toString();
    NUMERO_CLIENTS = query.value(nNumero).toString();
    DATEA = query.value(ndatea).toDate();


    return true;
}

// Tri par ID
QSqlQueryModel* clients::tri_ID()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT ORDER BY ID_CLIENTS ASC");
    return model;
}





// (Exemple) Méthode stat si besoin d'effectuer des requêtes statistiques
QSqlQueryModel* clients::stat()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    // Exemple : regrouper par NOM_CLIENTS
    model->setQuery("SELECT NOM_CLIENTS, COUNT(*) as Nombre FROM CLIENT GROUP BY NOM_CLIENTS");
    return model;
}


