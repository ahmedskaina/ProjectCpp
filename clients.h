#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QSqlQueryModel>
#include <QImage>
#include <QDate>

class clients
{
public:
    // Constructeurs
    clients();
    // Constructeur avec paramètres (si nécessaire)
    clients(int id, const QString &nom, const QString &prenom, const QString &adresse, QString numero,QDate date);

    // Getters
    int get_ID_CLIENTS() const;
    QString get_NOM_CLIENTS() const;
    QString get_PRENOM_CLIENTS() const;
    QString get_ADRESS_CLIENTS() const;
    QString get_NUMERO_CLIENTS() const;
    QDate get_DATEA() const;

    // Setters
    void set_ID_CLIENTS(int id);
    void set_NOM_CLIENTS(const QString &nom);
    void set_PRENOM_CLIENTS(const QString &prenom);
    void set_ADRESS_CLIENTS(const QString &adresse);
    void set_NUMERO_CLIENTS(QString numero);
    void set_DATEA(QDate date);

    // Méthodes CRUD
    bool Ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int id);

    // Recherche et tri
    bool RechercheClientParID(int IDrecherche);
    QSqlQueryModel* tri_ID();



    // Statistiques (exemple)
    QSqlQueryModel* stat();

    // Méthode d’exemple pour récupérer une image
    QImage GetPhoto(const QString &filePath);

private:
    int ID_CLIENTS;
    QString NOM_CLIENTS;
    QString PRENOM_CLIENTS;
    QString ADRESS_CLIENTS;
    QString NUMERO_CLIENTS;
    QDate DATEA;
};

#endif // CLIENTS_H
