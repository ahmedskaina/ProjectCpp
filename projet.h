#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>

class projet
{
private:
    // Project properties
    int id_projet;
    int id_client;
    int id_responsable;
    QString nom_projet;
    QString description;
    QString statut;
    QDate date_debut;

    // (Optional) In‑memory history list
    // You can keep this if needed for other purposes.
    // Here we use direct file logging, so it isn’t required.
    // QList<QString> historyList;
    // QString historiqueFileName = "historique.txt";

public:
    // Constructors
    projet();
    projet(int id_projet, QString nom_projet, QString description, QString statut,
           int id_client, int id_responsable, QDate date_debut);

    // History method (explicit action parameter)
    void addToHistory(int projectId, const QString &action);
    void writeHistoryToFile(const QString &fileName);

    // Getters
    QString getNomProjet()       { return nom_projet; }
    QString getDescription()     { return description; }
    QString getStatut()          { return statut; }
    int getIdClient()            { return id_client; }
    int getIdResponsable()       { return id_responsable; }
    int getIdProjet()            { return id_projet; }
    QDate getDateDebut()         { return date_debut; }

    // Setters
    void setNomProjet(QString val)       { nom_projet = val; }
    void setDescription(QString val)     { description = val; }
    void setStatut(QString val)          { statut = val; }
    void setIdClient(int val)            { id_client = val; }
    void setIdResponsable(int val)       { id_responsable = val; }
    void setIdProjet(int val)            { id_projet = val; }
    void setDateDebut(QDate val)         { date_debut = val; }

    // CRUD operations
    bool ajouter_projet();
    QSqlQueryModel* afficher_projets();
    bool modifier_projet();
    bool supprimer_projet(const QString &id_projetStr);

    // Other methods
    QSqlQueryModel* trierParStatut();
    QSqlQueryModel* trierParID();
    QSqlQueryModel* trierParNom();
    QSqlQueryModel* rechercherParId(int id_projet);
    bool exporterPDF(const QString &fileName, QSqlQueryModel* model);
};

#endif // PROJET_H
