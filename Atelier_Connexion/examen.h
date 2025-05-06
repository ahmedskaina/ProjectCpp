#ifndef EXAMEN_H
#define EXAMEN_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Examen
{
public:
    Examen();
    Examen(int, int, QString, QDate, int, QString, QString, QString);

    int getIdExamen();
    int getCodeExamen();
    QString getNomExamen();
    QDate getDateExamen();
    int getDureeExamen();
    QString getTypeExamen();
    QString getFichierExamen();
    QString getStatutExamen();

    void setIdExamen(int);
    void setCodeExamen(int);
    void setNomExamen(QString);
    void setDateExamen(QDate);
    void setDureeExamen(int);
    void setTypeExamen(QString);
    void setFichierExamen(QString);
    void setStatutExamen(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel* tri_id();
    QSqlQueryModel* tri_nom();
    bool genererPDF();
    QSqlQueryModel* chercherSelonId(QString);

private:
    int id_examen, code_examen, duree_examen;
    QString nom_examen, type_examen, fichier_examen, statut_examen;
    QDate date_examen;
};

#endif // EXAMEN_H
