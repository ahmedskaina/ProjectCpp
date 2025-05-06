#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int, QString, QString, int, QString, QString);

    int getIdEmployee();
    QString getNomEmployee();
    QString getPrenomEmployee();
    int getNumeroEmployee();
    QString getEmailEmployee();
    QString getPasswordEmployee();

    void setIdEmployee(int);
    void setNomEmployee(QString);
    void setPrenomEmployee(QString);
    void setNumeroEmployee(int);
    void setEmailEmployee(QString);
    void setPasswordEmployee(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* recherche(QString);
    QSqlQueryModel* tri_id();
    QSqlQueryModel* tri_nom();
  bool genererPDF();
private:
    int id_employee, numero_employee;
    QString nom_employee, prenom_employee, email_employee, password_employee;
};

#endif // EMPLOYE_H
