#include "projet.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QPrinter>
#include <QPainter>
#include <QFont>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QMarginsF>
#include <QPageSize>
#include <QPageLayout>
#include <QFile>
#include <QDebug>
#include <QPdfWriter>
#include <QFileInfo>
#include <QTextDocument>
#include <QDateTime>

// --------------------------
// Constructors
// --------------------------
projet::projet()
{
    id_projet = 0;
    id_client = 0;
    id_responsable = 0;
    nom_projet = "";
    description = "";
    statut = "";
    date_debut = QDate::currentDate();
}

projet::projet(int id_projet, QString nom_projet, QString description, QString statut,
               int id_client, int id_responsable, QDate date_debut)
{
    this->id_projet = id_projet;
    this->nom_projet = nom_projet;
    this->description = description;
    this->statut = statut;
    this->id_client = id_client;
    this->id_responsable = id_responsable;
    this->date_debut = date_debut;
}

// --------------------------
// History Functions (explicit action)
// --------------------------
void projet::addToHistory(int projectId, const QString &action)
{
    // Define the file path (you can adjust it as needed)
    QString cheminFichier = "C:/Users/ADAM/Desktop/adam/historique.txt";
    QFile file(cheminFichier);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier historique.";
        return;
    }
    QTextStream out(&file);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString message;

    if(action.compare("ajouter", Qt::CaseInsensitive)==0)
         message = "Projet ajouté : ";
    else if(action.compare("modifier", Qt::CaseInsensitive)==0)
         message = "Projet modifié : ";
    else if(action.compare("supprimer", Qt::CaseInsensitive)==0)
         message = "Projet supprimé : ";
    else
         message = "Action inconnue sur projet ID : ";

    // We use getNomProjet() as the project name in this instance.
    // In a more complex scenario you might query the DB.
    out << currentDateTime.toString("yyyy-MM-dd hh:mm:ss") << " - "
        << message << nom_projet << " (ID: " << projectId << ")\n";
    file.close();
}

void projet::writeHistoryToFile(const QString &fileName)
{
    // If you're keeping history in memory, write it out.
    // For this example, we are logging directly to file in addToHistory().
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier historique.";
        return;
    }
    QTextStream out(&file);
    // If you had stored entries in historyList, you could loop and output them:
    // for (const QString &entry : historyList) {
    //     out << entry << "\n";
    // }
    file.close();
    qDebug() << "Historique enregistré dans le fichier " << fileName;
}

// --------------------------
// CRUD Functions
// --------------------------
bool projet::ajouter_projet()
{
    // Check if the project already exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM PROJET WHERE ID_PROJET = :ID_PROJET");
    checkQuery.bindValue(":ID_PROJET", id_projet);
    if (!checkQuery.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la vérification de l'existence de l'ID du projet.");
        return false;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::critical(nullptr, "Information", "L'ID du projet existe déjà.");
        return false;
    }

    // Insert the new project into the DB
    QSqlQuery query;
    query.prepare("INSERT INTO PROJET(ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, ID_CLIENT, ID_RESPONSABLE, DATE_DEBUT) "
                  "VALUES(:ID_PROJET, :NOM_PROJET, :DESCRIPTION, :STATUT, :ID_CLIENT, :ID_RESPONSABLE, :DATE_DEBUT)");
    query.bindValue(":ID_PROJET", id_projet);
    query.bindValue(":NOM_PROJET", nom_projet);
    query.bindValue(":DESCRIPTION", description);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_CLIENT", id_client);
    query.bindValue(":ID_RESPONSABLE", id_responsable);
    query.bindValue(":DATE_DEBUT", date_debut);

    if (query.exec()) {
        addToHistory(id_projet, "ajouter");
        return true;
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de l'insertion du projet.\n" + query.lastError().text());
        return false;
    }
}

QSqlQueryModel* projet::afficher_projets()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, ID_CLIENT, ID_RESPONSABLE, DATE_DEBUT FROM PROJET");
    if (model->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la récupération des données : " + model->lastError().text());
        return nullptr;
    }
    // Format the date in column 6
    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex dateDebutIndex = model->index(i, 6);
        if (dateDebutIndex.isValid()) {
            QString dateDebutString = dateDebutIndex.data().toDate().toString("yyyy-MM-dd");
            model->setData(dateDebutIndex, dateDebutString);
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Erreur lors du traitement de la colonne DATE_DEBUT.");
            return nullptr;
        }
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PROJET"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_RESPONSABLE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
    return model;
}

bool projet::modifier_projet()
{
    if (nom_projet.isEmpty() || description.isEmpty() || statut.isEmpty()) {
        QMessageBox::critical(nullptr, "Information", "Veuillez remplir tous les champs requis.");
        return false;
    }

    // Check if the project exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM PROJET WHERE ID_PROJET = :ID_PROJET");
    checkQuery.bindValue(":ID_PROJET", id_projet);
    if (!checkQuery.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la vérification de l'existence de l'ID du projet : " + checkQuery.lastError().text());
        return false;
    }
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        QMessageBox::critical(nullptr, "Information", "L'ID du projet n'existe pas.");
        return false;
    }

    // Update the project
    QSqlQuery query;
    query.prepare("UPDATE PROJET SET NOM_PROJET = :NOM_PROJET, DESCRIPTION = :DESCRIPTION, STATUT = :STATUT, "
                  "ID_CLIENT = :ID_CLIENT, ID_RESPONSABLE = :ID_RESPONSABLE, DATE_DEBUT = :DATE_DEBUT "
                  "WHERE ID_PROJET = :ID_PROJET");
    query.bindValue(":ID_PROJET", id_projet);
    query.bindValue(":NOM_PROJET", nom_projet);
    query.bindValue(":DESCRIPTION", description);
    query.bindValue(":STATUT", statut);
    query.bindValue(":ID_CLIENT", id_client);
    query.bindValue(":ID_RESPONSABLE", id_responsable);
    query.bindValue(":DATE_DEBUT", date_debut);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la mise à jour du projet : " + query.lastError().text());
        return false;
    }

    QMessageBox::information(nullptr, "Succès", "Projet modifié avec succès.");
    addToHistory(id_projet, "modifier");
    return true;
}

bool projet::supprimer_projet(const QString &id_projetStr)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PROJET WHERE ID_PROJET = :ID_PROJET");
    query.bindValue(":ID_PROJET", id_projetStr);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de la suppression du projet : " + query.lastError().text());
        return false;
    }
    QMessageBox::information(nullptr, "Succès", "Projet supprimé avec succès.");
    int projId = id_projetStr.toInt();
    addToHistory(projId, "supprimer");
    return true;
}

// --------------------------
// Tri & Recherche
// --------------------------
QSqlQueryModel* projet::trierParStatut()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM PROJET ORDER BY STATUT ASC";
    QSqlQuery qry;
    qry.prepare(queryStr);
    if (!qry.exec()) {
        return model;
    }
    model->setQuery(qry);
    return model;
}

QSqlQueryModel* projet::trierParID()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM PROJET ORDER BY ID_PROJET ASC";
    QSqlQuery qry;
    qry.prepare(queryStr);
    if (!qry.exec()) {
        return model;
    }
    model->setQuery(qry);
    return model;
}

QSqlQueryModel* projet::trierParNom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM PROJET ORDER BY NOM_PROJET ASC";
    QSqlQuery qry;
    qry.prepare(queryStr);
    if (!qry.exec()) {
        return model;
    }
    model->setQuery(qry);
    return model;
}

QSqlQueryModel* projet::rechercherParId(int id_proj)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM PROJET WHERE ID_PROJET = :id_projet";
    QSqlQuery qry;
    qry.prepare(queryStr);
    qry.bindValue(":id_projet", id_proj);
    if (!qry.exec()) {
        return model;
    }
    model->setQuery(qry);
    addToHistory(id_proj, "consulter");
    return model;
}

// --------------------------
// Export PDF
// --------------------------
bool projet::exporterPDF(const QString &fileName, QSqlQueryModel* model)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Landscape);
    printer.setOutputFileName(fileName);
    QMarginsF margins(10, 10, 10, 10);
    printer.setPageMargins(margins, QPageLayout::Millimeter);

    QPainter painter(&printer);
    if (!painter.isActive()) {
        QMessageBox::warning(nullptr, "Erreur", "Impossible de dessiner sur l'imprimante.");
        return false;
    }
    painter.setFont(QFont("Arial", 10));
    QColor headerColor(49, 164, 180);
    QColor cellColor(230, 244, 241);
    int x = 10;
    int y = 20;
    int rowHeight = 20;
    int colWidth = 110;
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.setPen(QPen(headerColor));
    painter.drawText(x, y, "Liste des Projets");
    y += 30;
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(QBrush(headerColor));
    painter.setPen(QPen(Qt::black));
    QStringList headers = {"ID Projet", "Nom du Projet", "Description", "Statut", "ID Client", "ID Responsable", "Date de Début"};
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
        painter.drawText(x + col * colWidth + 5, y + 10, headers[col]);
    }
    y += rowHeight;
    painter.setFont(QFont("Arial", 10));
    painter.setBrush(QBrush(cellColor));
    for (int row = 0; row < model->rowCount(); ++row) {
        if (y + rowHeight > printer.pageRect(QPrinter::Point).bottom()) {

            painter.end();
            printer.newPage();
            painter.begin(&printer);
            y = 40;
            for (int col = 0; col < headers.size(); ++col) {
                painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
                painter.drawText(x + col * colWidth + 5, y + 10, headers[col]);
            }
            y += rowHeight;
        }
        for (int col = 0; col < headers.size(); ++col) {
            painter.setPen(QPen(Qt::black));
            painter.drawRect(x + col * colWidth, y, colWidth, rowHeight);
            QString data = model->data(model->index(row, col)).toString();
            painter.drawText(x + col * colWidth + 5, y + 10, data);
        }
        y += rowHeight;
    }
    painter.end();
    return true;
}
