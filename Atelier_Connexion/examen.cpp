#include "examen.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QMessageBox>

Examen::Examen()
{
    id_examen = 0;
    code_examen = 0;
    nom_examen = "";
    date_examen = QDate::currentDate();
    duree_examen = 0;
    type_examen = "";
    fichier_examen = "";
    statut_examen = "";
}

Examen::Examen(int id_examen, int code_examen, QString nom_examen, QDate date_examen, int duree_examen,
               QString type_examen, QString fichier_examen, QString statut_examen)
{
    this->id_examen = id_examen;
    this->code_examen = code_examen;
    this->nom_examen = nom_examen;
    this->date_examen = date_examen;
    this->duree_examen = duree_examen;
    this->type_examen = type_examen;
    this->fichier_examen = fichier_examen;
    this->statut_examen = statut_examen;
}

int Examen::getIdExamen() { return id_examen; }
int Examen::getCodeExamen() { return code_examen; }
QString Examen::getNomExamen() { return nom_examen; }
QDate Examen::getDateExamen() { return date_examen; }
int Examen::getDureeExamen() { return duree_examen; }
QString Examen::getTypeExamen() { return type_examen; }
QString Examen::getFichierExamen() { return fichier_examen; }
QString Examen::getStatutExamen() { return statut_examen; }

void Examen::setIdExamen(int id_examen) { this->id_examen = id_examen; }
void Examen::setCodeExamen(int code_examen) { this->code_examen = code_examen; }
void Examen::setNomExamen(QString nom_examen) { this->nom_examen = nom_examen; }
void Examen::setDateExamen(QDate date_examen) { this->date_examen = date_examen; }
void Examen::setDureeExamen(int duree_examen) { this->duree_examen = duree_examen; }
void Examen::setTypeExamen(QString type_examen) { this->type_examen = type_examen; }
void Examen::setFichierExamen(QString fichier_examen) { this->fichier_examen = fichier_examen; }
void Examen::setStatutExamen(QString statut_examen) { this->statut_examen = statut_examen; }

bool Examen::ajouter()
{
    QSqlQuery query;

    // Prepare the SQL insert statement without the ID_EXAMEN field (auto-incremented)
    query.prepare("INSERT INTO EXAMEN (ID_EXAMEN,CODE_EXAMEN, NOM_EXAMEN, DATE_EXAMEN, DUREE_EXAMEN, TYPE_EXAMEN, FICHIER_EXAMEN, STATUT_EXAMEN) "
                  "VALUES (:id_examen,:code_examen, :nom_examen, :date_examen, :duree_examen, :type_examen, :fichier_examen, :statut_examen)");

    // Bind the values to the named placeholders*
 query.bindValue(":id_examen", id_examen);
    query.bindValue(":code_examen", code_examen);
    query.bindValue(":nom_examen", nom_examen);
    query.bindValue(":date_examen", date_examen);
    query.bindValue(":duree_examen", duree_examen);
    query.bindValue(":type_examen", type_examen);
    query.bindValue(":fichier_examen", fichier_examen);
    query.bindValue(":statut_examen", statut_examen);

    // Execute the query and check if it was successful
    if (!query.exec()) {
        // Log the query and error details for debugging purposes
        qDebug() << "Error executing query: " << query.lastQuery();
        qDebug() << "Error details: " << query.lastError().text();
        return false;  // Return false if query execution failed
    }

    // Log success if the query was executed successfully
    qDebug() << "Examen added successfully!";
    return true;  // Return true if the insertion was successful
}



bool Examen::supprimer(int id_examen)
{
    QSqlQuery query;
    query.prepare("DELETE FROM examen WHERE ID_EXAMEN = :ID_EXAMEN");
    query.bindValue(":ID_EXAMEN", id_examen);

    if (!query.exec()) {
        qDebug() << "Error deleting exam:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Examen::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EXAMEN, CODE_EXAMEN, NOM_EXAMEN, DATE_EXAMEN, DUREE_EXAMEN, TYPE_EXAMEN, STATUT_EXAMEN FROM examen");

    if (model->lastError().isValid()) {
        qDebug() << "Error displaying exams:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code Examen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Examen"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Examen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Durée Examen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type Examen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut Examen"));
    return model;
}

bool Examen::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE examen SET "
                  "code_examen = :code_examen, "
                  "nom_examen = :nom_examen, "
                  "date_examen = :date_examen, "
                  "duree_examen = :duree_examen, "
                  "type_examen = :type_examen, "
                  "fichier_examen = :fichier_examen, "
                  "statut_examen = :statut_examen "
                  "WHERE id_examen = :id_examen");

    query.bindValue(":id_examen", id_examen);
    query.bindValue(":code_examen", code_examen);
    query.bindValue(":nom_examen", nom_examen);
    query.bindValue(":date_examen", date_examen);
    query.bindValue(":duree_examen", duree_examen);
    query.bindValue(":type_examen", type_examen);
    query.bindValue(":fichier_examen", fichier_examen);
    query.bindValue(":statut_examen", statut_examen);

    return query.exec();
}



QSqlQueryModel* Examen::recherche(QString nom_examen)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EXAMEN, CODE_EXAMEN, NOM_EXAMEN, DATE_EXAMEN, DUREE_EXAMEN, TYPE_EXAMEN, STATUT_EXAMEN "
                    "FROM examen WHERE NOM_EXAMEN LIKE '" + nom_examen + "%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code Examen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Examen"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Examen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Durée Examen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type Examen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut Examen"));
    return model;
}

QSqlQueryModel* Examen::tri_id()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EXAMEN, CODE_EXAMEN, NOM_EXAMEN, DATE_EXAMEN, DUREE_EXAMEN, TYPE_EXAMEN, STATUT_EXAMEN "
                    "FROM examen ORDER BY ID_EXAMEN ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting by ID:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code Examen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Examen"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Examen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Durée Examen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type Examen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut Examen"));
    return model;
}

QSqlQueryModel* Examen::tri_nom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EXAMEN, CODE_EXAMEN, NOM_EXAMEN, DATE_EXAMEN, DUREE_EXAMEN, TYPE_EXAMEN, STATUT_EXAMEN "
                    "FROM examen ORDER BY NOM_EXAMEN ASC");

    if (model->lastError().isValid()) {
        qDebug() << "Error sorting by name:" << model->lastError().text();
        return nullptr;
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Code Examen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Examen"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Examen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Durée Examen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type Examen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut Examen"));
    return model;
}

#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QFileDialog>
#include <QFileDialog>

bool Examen::genererPDF()
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
    painter.drawText(3000, 2000, "Liste des Examens");

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // 🖋️ Dessiner les informations sur chaque examen (sans tableau)
    int verticalPosition = 2500; // Position de départ pour les premières informations

    // 🗂️ Récupérer les données de la base de données
    QSqlQuery query;
    query.prepare("SELECT nom_examen, date_examen, duree_examen, type_examen, fichier_examen, statut_examen FROM examen");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la requête SQL.");
        return false;
    }

    // Afficher les données
    while (query.next()) {
        painter.drawText(1000, verticalPosition, "Nom Examen: " + query.value(0).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Date Examen: " + query.value(1).toDate().toString("dd/MM/yyyy"));
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Durée Examen: " + query.value(2).toString() + " minutes");
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Type Examen: " + query.value(3).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Fichier Examen: " + query.value(4).toString());
        verticalPosition += 400;

        painter.drawText(1000, verticalPosition, "Statut Examen: " + query.value(5).toString());
        verticalPosition += 600; // Espacement pour le prochain examen
    }

    // 🎉 Terminer l'écriture et afficher un message de succès
    painter.end();
    QMessageBox::information(nullptr, "Succès", "PDF généré avec succès.");

    return true;
}
