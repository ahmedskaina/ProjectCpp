#include "employe.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>

Employe::Employe() {}

Employe::Employe(int id, QString nom, QString prenom, int numero, QString email, QString password)
{
    this->id_employee = id;
    this->nom_employee = nom;
    this->prenom_employee = prenom;
    this->numero_employee = numero;
    this->email_employee = email;
    this->password_employee = password;
}

// Getters
int Employe::getIdEmployee() { return id_employee; }
QString Employe::getNomEmployee() { return nom_employee; }
QString Employe::getPrenomEmployee() { return prenom_employee; }
int Employe::getNumeroEmployee() { return numero_employee; }
QString Employe::getEmailEmployee() { return email_employee; }
QString Employe::getPasswordEmployee() { return password_employee; }

// Setters
void Employe::setIdEmployee(int id) { id_employee = id; }
void Employe::setNomEmployee(QString nom) { nom_employee = nom; }
void Employe::setPrenomEmployee(QString prenom) { prenom_employee = prenom; }
void Employe::setNumeroEmployee(int numero) { numero_employee = numero; }
void Employe::setEmailEmployee(QString email) { email_employee = email; }
void Employe::setPasswordEmployee(QString password) { password_employee = password; }

// Ajouter un employé
bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (ID_EMPLOYEE, NOM_EMPLOYEE, PRENOM_EMPLOYEE, NUMERO_EMPLOYEE, EMAIL_EMPLOYEE, PASSWORD_EMPLOYEE) "
                  "VALUES (:id, :nom, :prenom, :numero, :email, :password)");
    query.bindValue(":id", id_employee);
    query.bindValue(":nom", nom_employee);
    query.bindValue(":prenom", prenom_employee);
    query.bindValue(":numero", numero_employee);
    query.bindValue(":email", email_employee);
    query.bindValue(":password", password_employee);

    return query.exec();
}

// Afficher la liste des employés
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEE");
    return model;
}

// Supprimer un employé par ID
bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE ID_EMPLOYEE = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Modifier un employé
bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET NOM_EMPLOYEE = :nom, PRENOM_EMPLOYEE = :prenom, NUMERO_EMPLOYEE = :numero, "
                  "EMAIL_EMPLOYEE = :email, PASSWORD_EMPLOYEE = :password WHERE ID_EMPLOYEE = :id");
    query.bindValue(":id", id_employee);
    query.bindValue(":nom", nom_employee);
    query.bindValue(":prenom", prenom_employee);
    query.bindValue(":numero", numero_employee);
    query.bindValue(":email", email_employee);
    query.bindValue(":password", password_employee);

    return query.exec();
}

// Recherche un employé par son nom
QSqlQueryModel* Employe::recherche(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYEE WHERE NOM_EMPLOYEE LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");
    query.exec();
    model->setQuery(query);
    return model;
}

// Trier les employés par ID
QSqlQueryModel* Employe::tri_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEE ORDER BY ID_EMPLOYEE ASC");
    return model;
}

// Trier les employés par nom
QSqlQueryModel* Employe::tri_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEE ORDER BY NOM_EMPLOYEE ASC");
    return model;
}
#include "employe.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>

bool Employe::genererPDF()
{
    // Ouvrir le dialogue de sauvegarde pour que l'utilisateur choisisse le chemin de destination
    QString outputPath = QFileDialog::getSaveFileName(nullptr, "Enregistrer le PDF", "", "PDF Files (*.pdf)");

    // Vérifier si l'utilisateur a annulé la sélection du fichier
    if (outputPath.isEmpty()) {
        QMessageBox::information(nullptr, "Annulé", "Aucun fichier n'a été sélectionné.");
        return false;
    }

    // Vérification si le répertoire existe
    QFileInfo fileInfo(outputPath);
    if (!fileInfo.dir().exists()) {
        QMessageBox::critical(nullptr, "Erreur", "Le répertoire n'existe pas ou n'est pas accessible en écriture.");
        return false;
    }

    // Création du QPdfWriter avec le chemin spécifié par l'utilisateur
    QPdfWriter pdf(outputPath);
    QPainter painter(&pdf);

    if (!painter.isActive()) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible d'écrire dans le fichier PDF.");
        return false;
    }

    // 🎨 Styles et titre
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(3000, 2000, "Liste des Employés");

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // 🖋️ Dessiner les informations sur chaque employé (sans tableau)
    int verticalPosition = 2500; // Position de départ pour les premières informations

    // 🗂️ Récupérer les données de la base de données
    QSqlQuery query;
    query.prepare("SELECT NOM_EMPLOYEE, PRENOM_EMPLOYEE, NUMERO_EMPLOYEE, EMAIL_EMPLOYEE FROM EMPLOYEE");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la requête SQL.");
        return false;
    }

    // Afficher les données
    while (query.next()) {
        painter.drawText(1000, verticalPosition, "Nom: " + query.value(0).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Prénom: " + query.value(1).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Numéro: " + query.value(2).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Email: " + query.value(3).toString());
        verticalPosition += 600; // Espacement pour le prochain employé
    }

    // 🎉 Terminer l'écriture et afficher un message de succès
    painter.end();
    QMessageBox::information(nullptr, "Succès", "PDF généré avec succès.");

    return true;
}
