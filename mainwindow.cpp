#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
#include<QFileDialog>
#include "qrcodegen.hpp"  // Inclure la bibliothèque qrcodegen
#include <QSslSocket>
#include <QDialog>
#include<QSqlQuery>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QMessageBox>
#include <QInputDialog>
#include <QProcess>
#include <QMessageBox>
#include <QFileInfo>
#include "serialcommunication.h"
using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SerialCommunication *serial = new SerialCommunication(QSqlDatabase::database("maConnexion"), this);

    if (serial->openPort("COM4", 9600)) {
        qDebug() << "✅ Port série connecté avec succès.";
    } else {
        qDebug() << "❌ Échec de la connexion au port série.";
    }
    ui->statut->addItem("statut de projet");
    ui->statut->addItem("Non démarré");
    ui->statut->addItem("En préparation");
    ui->statut->addItem("En cours");
    ui->statut->addItem("En pause");
    ui->statut->addItem("En révision");
    ui->statut->addItem("Terminé");
    ui->statut->addItem("Annulé");
    ui->statut->addItem("En test");
    ui->statut->addItem("En attente de validation");
    ui->statut->addItem("Livré");
    ui->statut->addItem("En déploiement");
}

MainWindow::~MainWindow()
{
    delete ui;


}
void MainWindow::clearFields() {
    // Réinitialiser les champs de texte
    ui->id->clear();
    ui->nom_projet->clear();
    ui->plainTextEdit->clear();
    ui->idrep->clear();
    ui->id_2->clear();

    // Réinitialiser la date
    ui->dateTimeEdit->setDate(QDate::currentDate());  // Remet la date à aujourd'hui (ou la valeur par défaut souhaitée)
ui->recherche->clear();
    // Réinitialiser le statut
    ui->statut->setCurrentIndex(0);  // Remet le premier élément sélectionné dans le combo box (si tu veux le réinitialiser à une valeur vide, utilise un index spécifique)
}



void MainWindow::on_btnPredire_clicked()
{
    // Récupérer l'ID du projet depuis le champ de recherche
    QString id_projet_str = ui->recherche->text();
    bool ok;
    int id_projet = id_projet_str.toInt(&ok); // Convertir en entier

    if (!ok || id_projet <= 0) {
        QMessageBox::warning(this, "ID invalide", "Veuillez sélectionner un projet valide pour prédire le coût.");
        return;
    }

    // Rechercher les informations du projet via l'ID dans la base de données
    QSqlQuery query;
    query.prepare("SELECT description FROM projet WHERE id_projet = :id");
    query.bindValue(":id", id_projet);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Projet introuvable", "Aucun projet trouvé pour cet ID.");
        return;
    }

    QString description = query.value(0).toString(); // colonne "description"
    if (description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La description du projet ne peut pas être vide.");
        return;
    }

    // Préparation et lancement du script Python
    QProcess process;
    QString program = "python";  // ou "python3" selon votre système
    QStringList arguments;
    arguments << "predict_cost.py" << description;

    QString workingDir = QCoreApplication::applicationDirPath();
    process.setWorkingDirectory(workingDir);

    process.start(program, arguments);
    if (!process.waitForStarted()) {
        QMessageBox::critical(this, "Erreur", "Impossible de démarrer le script Python.");
        return;
    }

    process.waitForFinished();

    QString output = process.readAllStandardOutput().trimmed();
    QString error = process.readAllStandardError().trimmed();

    if (!output.isEmpty()) {
        ui->label_prediction->setText("Estimation de dépense : " + output + " TND");
    } else {
        QMessageBox::warning(this, "Erreur", "Le script a échoué.\nErreur : " + error);
    }
}



void MainWindow::on_ajout_clicked()
{
    // Vérification de la saisie pour chaque champ

    // Vérifier que l'ID du projet est valide
    int id_projet = ui->id->text().toInt();
    if (id_projet == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du projet doit être un entier valide.");
        return;
    }

    // Vérifier que le nom du projet n'est pas vide
    QString nom_projet = ui->nom_projet->text();
    if (nom_projet.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le nom du projet ne peut pas être vide.");
        return;
    }

    // Vérifier que la description du projet n'est pas vide
    QString description = ui->plainTextEdit->toPlainText();
    if (description.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "La description du projet ne peut pas être vide.");
        return;
    }

    // Vérifier que l'ID du responsable est valide
    int id_responsable = ui->idrep->text().toInt();
    if (id_responsable == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du responsable doit être un entier valide.");
        return;
    }

    // Vérifier que l'ID du client est valide
    int id_client = ui->id_2->text().toInt();
    if (id_client == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du client doit être un entier valide.");
        return;
    }

    // Vérifier que la date de début est valide
    QDate date_debut = ui->dateTimeEdit->date();
    if (!date_debut.isValid()) {
        QMessageBox::warning(nullptr, "Erreur", "La date de début est invalide.");
        return;
    }

    // Vérifier que le statut est sélectionné
    QString statut = ui->statut->currentText();
    if (statut.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le statut du projet doit être sélectionné.");
        return;
    }

    // Créer un objet projet avec les informations validées
    projet p(id_projet, nom_projet, description, statut, id_client, id_responsable, date_debut);

    // Essayer d'ajouter le projet
    bool test = p.ajouter_projet();
    if (test) {
        QMessageBox::information(nullptr, "Succès", "Ajout effectué avec succès");
    } else {
        QMessageBox::warning(nullptr, "Échec", "Ajout non effectué");
    }

    // Effacer les champs du formulaire
    clearFields();

    // Mettre à jour le modèle de la table pour afficher les projets
    ui->tableView->setModel(p.afficher_projets());
}


void MainWindow::on_afficher_clicked()
{
      ui->tableView->setModel(p.afficher_projets());
}
void MainWindow::on_modif_clicked()
{
    // Vérification de la saisie pour chaque champ

    // Vérifier que l'ID du projet est valide
    int id_projet = ui->id->text().toInt();
    if (id_projet == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du projet doit être un entier valide.");
        return;
    }

    // Vérifier que le nom du projet n'est pas vide
    QString nom_projet = ui->nom_projet->text();
    if (nom_projet.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le nom du projet ne peut pas être vide.");
        return;
    }

    // Vérifier que la description du projet n'est pas vide
    QString description = ui->plainTextEdit->toPlainText();
    if (description.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "La description du projet ne peut pas être vide.");
        return;
    }

    // Vérifier que l'ID du responsable est valide
    int id_responsable = ui->idrep->text().toInt();
    if (id_responsable == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du responsable doit être un entier valide.");
        return;
    }

    // Vérifier que l'ID du client est valide
    int id_client = ui->id_2->text().toInt();
    if (id_client == 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID du client doit être un entier valide.");
        return;
    }

    // Vérifier que la date de début est valide
    QDate date_debut = ui->dateTimeEdit->date();
    if (!date_debut.isValid()) {
        QMessageBox::warning(nullptr, "Erreur", "La date de début est invalide.");
        return;
    }

    // Vérifier que le statut est sélectionné
    QString statut = ui->statut->currentText();
    if (statut.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le statut du projet doit être sélectionné.");
        return;
    }

    // Créer un objet projet avec les informations validées
    projet p(id_projet, nom_projet, description, statut, id_client, id_responsable, date_debut);

    // Essayer de modifier le projet
    bool test = p.modifier_projet();
    if (test) {
        ui->tableView->setModel(p.afficher_projets());  // Recharger les données dans le tableView
        QMessageBox::information(nullptr, "Succès", "Modification effectuée avec succès");
    } else {
        QMessageBox::warning(nullptr, "Échec", "Erreur lors de la modification du projet");
    }

    // Effacer les champs du formulaire
    clearFields();
}


void MainWindow::on_supprimer_clicked()
{

            QString ID = ui->recherche->text();  // Assumes ID is displayed in a read-only field

                   if (ID.isEmpty()) {
                       QMessageBox::warning(this, "Attention", "Veuillez sélectionner un projet à supprimer.");
                       return;
                   }

                   // Afficher une boîte de confirmation avant de supprimer
                   QMessageBox::StandardButton reply;
                   reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer ce projet ?",
                                                 QMessageBox::Yes | QMessageBox::No);

                   if (reply == QMessageBox::Yes) {
                       projet p;  // Créer une instance de commandeC
                       bool test = p.supprimer_projet(ID);  // Appeler la méthode de suppression

                       if (test) {
                           ui->tableView->setModel(p.afficher_projets());  // Recharger les données dans le tableView
                        clearFields();
                       }
                   }
}

void MainWindow::on_rech_clicked()
{
    bool ok;
    int id_projet = ui->recherche->text().toInt(&ok);  // Convertir le texte de recherche en entier

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    projet p;
    QSqlQueryModel* model = p.rechercherParId(id_projet);

    if (model->rowCount() > 0) {
        // Affichage du modèle dans le QTableView
        ui->tableView->setModel(model);
    } else {
        QMessageBox::warning(this, "Résultat", "Aucun projet trouvé avec cet ID.");
    }
    clearFields();
}



void MainWindow::on_t_clicked()
{
    projet p;
      QSqlQueryModel* model = p.trierParNom();  // Appel de la fonction de tri

      if (model->rowCount() > 0) {
          ui->tableView->setModel(model);
          ui->tableView->setSortingEnabled(true);  // Permet de trier par colonnes
      } else {
          QMessageBox::warning(this, "Résultat", "Aucun projet trouvé.");
      }
}


void MainWindow::on_p_clicked()
{
    // Demander à l'utilisateur où enregistrer le fichier PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty()) {
        return;  // Si l'utilisateur annule la boîte de dialogue, rien n'est fait
    }

    // Créer un objet projet pour accéder à la méthode exporterPDF
    projet p;

    // Exporter les données de votre tableView en PDF
    if (p.exporterPDF(fileName, p.afficher_projets())) {
        QMessageBox::information(this, "Succès", "PDF exporté avec succès!");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'exportation du PDF.");
    }
}

void MainWindow::on_statistq_clicked()
{
    // Préparation de la requête SQL pour récupérer les statistiques des projets par statut
    QSqlQuery query;
    query.prepare("SELECT STATUT, COUNT(*) AS count FROM PROJET GROUP BY STATUT");

    if (query.exec()) {
        // Stockage temporaire des données
        QVector<QPair<QString, int>> data;
        int total = 0;

        // Première itération: accumuler la totalité des comptes et enregistrer les données
        while (query.next()) {
            QString statut = query.value("STATUT").toString();
            int count = query.value("count").toInt();
            data.append(qMakePair(statut, count));
            total += count;
        }

        // Création de la série de données pour le graphique
        QPieSeries *series = new QPieSeries();

        // Ajouter des slices à la série avec le nom du statut et le pourcentage uniquement
        for (const auto &pair : data) {
            QString statut = pair.first;
            int count = pair.second;
            double percentage = total != 0 ? (static_cast<double>(count) / total) * 100.0 : 0.0;

            // Format de l'étiquette: statut (percentage%)
            QString label = QString("%1 (%2%)")
                                .arg(statut)
                                .arg(QString::number(percentage, 'f', 2));

            // Ajouter le slice à la série
            QPieSlice *slice = series->append(label, count);
            slice->setLabelVisible();  // Afficher l'étiquette directement sur le slice
        }

        // Optionnel: Ajouter des couleurs personnalisées aux slices
        QList<QColor> couleurs = {Qt::cyan, Qt::magenta, Qt::yellow, Qt::green, Qt::red, Qt::blue};
        int i = 0;
        for (auto slice : series->slices()) {
            slice->setBrush(couleurs[i % couleurs.size()]);
            ++i;
        }

        // Créer et configurer le graphique
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques des statuts des projets");
        chart->setTitleFont(QFont("Arial", 8, QFont::Bold));
        chart->setTitleBrush(QBrush(Qt::darkBlue));
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->setAnimationOptions(QChart::SeriesAnimations); // Animation douce

        // Créer la vue du graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Nettoyer l'ancien graphique s’il existe dans le layout
        QLayoutItem *child;
        while ((child = ui->stat->layout()->takeAt(0)) != nullptr) {
            if (child->widget())
                delete child->widget();
            delete child;
        }

        // Ajouter le nouveau graphique à l'interface
        ui->stat->layout()->addWidget(chartView);
    } else {
        // Gestion d'erreur en cas d'échec de la requête
    }
}






void MainWindow::listprojet()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "La base de données n'est pas ouverte!";
        return;
    }

    model = new QSqlQueryModel(this);  // Important : créer le modèle si pas encore fait
    model->setQuery("SELECT ID_PROJET, NOM_PROJET, DESCRIPTION, STATUT, ID_CLIENT, ID_RESPONSABLE, DATE_DEBUT FROM PROJET");

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Description");
    model->setHeaderData(3, Qt::Horizontal, "Statut");
    model->setHeaderData(4, Qt::Horizontal, "ID Client");
    model->setHeaderData(5, Qt::Horizontal, "ID Responsable");
    model->setHeaderData(6, Qt::Horizontal, "Date Début");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::on_t_2_clicked()
{
    // Récupérer l'ID du projet depuis le champ de recherche
    QString id_projet_str = ui->recherche->text();
    bool ok;
    int id_projet = id_projet_str.toInt(&ok); // Convertir en entier

    if (!ok || id_projet <= 0) {
        QMessageBox::warning(this, "ID invalide", "Veuillez entrer un ID de projet valide.");
        return;
    }

    // Rechercher les informations du projet via l'ID dans la base de données
    QSqlQuery query;
    query.prepare("SELECT id_projet, nom_projet, description, statut, id_client, id_responsable, date_debut FROM projet WHERE id_projet = :id");
    query.bindValue(":id", id_projet);
    query.exec();

    if (query.next()) {
        QString id     = query.value(0).toString();
        QString nom    = query.value(1).toString();
        QString desc   = query.value(2).toString();
        QString stat   = query.value(3).toString();
        QString idc    = query.value(4).toString();
        QString idr    = query.value(5).toString();
        QString date   = query.value(6).toString();

        // Générer le texte du QR Code
        QString qrData = QString("ID Projet: %1\nNom: %2\nDescription: %3\nStatut: %4\nID Client: %5\nID Responsable: %6\nDate Début: %7")
                            .arg(id, nom, desc, stat, idc, idr, date);

        // Créer le QR Code
        using namespace qrcodegen;
        QrCode qr = QrCode::encodeText(qrData.toUtf8().data(), QrCode::Ecc::MEDIUM);
        int sz = qr.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
        im.fill(Qt::white);

        // Remplir l'image avec les modules du QR Code
        for (int y = 0; y < sz; ++y) {
            for (int x = 0; x < sz; ++x) {
                im.setPixel(x, y, qr.getModule(x, y) ? qRgb(0, 0, 0) : qRgb(255, 255, 255));
            }
        }

        // Afficher le QR Code dans le label
        ui->qrcodeLabel->setPixmap(QPixmap::fromImage(im.scaled(170, 170, Qt::KeepAspectRatio)));
    } else {
        QMessageBox::warning(this, "Projet introuvable", "Aucun projet trouvé pour cet ID.");
    }
}


void MainWindow::on_histo_clicked()
{
    QString cheminFichier =   "C:/Users/ADAM/Desktop/adam/historique.txt";
       QFile file( cheminFichier);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           // Afficher un message d'erreur si le fichier ne peut pas être ouvert
           QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
           return;
       }

       // Lire le contenu du fichier
       QTextStream in(&file);
       QString historique = in.readAll();

       // Fermer le fichier
       file.close();

       // Afficher le contenu de l'historique dans une boîte de dialogue
       QMessageBox msgBox;
       msgBox.setWindowTitle("Historique");
       msgBox.setText(historique);
       msgBox.exec();
}
void  MainWindow::afficherHistorique()
{
    // Spécifier le chemin complet du fichier historique
    QString cheminFichier =   "C:/Users/ADAM/Desktop/adam/historique.txt";
    // Ouvrir le fichier en écriture (mode Append)
    QFile file(cheminFichier);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur lors de l'ouverture du fichier historique.";
        return;
    }

    // Créer un flux texte pour écrire dans le fichier
    QTextStream out(&file);

    // Obtenir la date et l'heure actuelles
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // Écrire dans le fichier
    out << "Actions enregistrées à " << currentDateTime.toString() << "\n";

    // Fermer le fichier
    file.close();

    // Afficher un message pour indiquer que les actions ont été enregistrées dans l'historique
    QMessageBox::information(this, "Historique", "Les actions ont été enregistrées dans l'historique." );
    QDesktopServices::openUrl(QUrl::fromLocalFile(cheminFichier));
}


void MainWindow::on_sendMail_clicked()
{
    QString serveur = "smtp.gmail.com";
              int port = 587; // Port pour SMTP avec STARTTLS

              // Informations de l'expéditeur et du destinataire
              QString expediteur = "adammahrssi02@gmail.com";
              QString destinataire = ui->dest->toPlainText();

              QString subject = "[Urgent] A propos notre Projet  ";

              // Détails du message
               QString corps = ui->contenu->toPlainText();

              // Connexion au serveur SMTP
              QSslSocket socket;
              socket.connectToHost(serveur, port);
              if (!socket.waitForConnected()) {
                  qDebug() << "Échec de connexion au serveur SMTP:" << socket.errorString();
                  return;
              }

              // Attente de la réponse du serveur
              if (!socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP:" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse initiale du serveur

              // Envoi de la commande EHLO
              socket.write("EHLO localhost\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (EHLO):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après EHLO

              // Envoi de la commande STARTTLS
              socket.write("STARTTLS\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (STARTTLS):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après STARTTLS

              // Démarrer le chiffrement
              socket.startClientEncryption();
              if (!socket.waitForEncrypted()) {
                  qDebug() << "Échec du chiffrement:" << socket.errorString();
                  return;
              }

              // Envoi de la commande AUTH LOGIN
              socket.write("AUTH LOGIN\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (AUTH LOGIN):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après AUTH LOGIN

              // Envoi du nom d'utilisateur encodé en Base64
              socket.write(QByteArray().append(expediteur.toUtf8()).toBase64() + "\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (Nom d'utilisateur):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du nom d'utilisateur

              // Envoi du mot de passe encodé en Base64
              socket.write(QByteArray().append("bjvp cxnx nzqv kdyx").toBase64() + "\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Échec de l'authentification SMTP (Mot de passe):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du mot de passe

              // Envoi de la commande MAIL FROM
              socket.write("MAIL FROM:<" + expediteur.toUtf8() + ">\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (MAIL FROM):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après MAIL FROM

              // Envoi de la commande RCPT TO
              socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (RCPT TO):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après RCPT TO

              // Envoi de la commande DATA
              socket.write("DATA\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Délai d'attente de réponse du serveur SMTP (DATA):" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après DATA

              // Envoi des en-têtes et du corps du message
              socket.write("From: " + expediteur.toUtf8() + "\r\n");
              socket.write("To: " + destinataire.toUtf8() + "\r\n");
              socket.write("Subject: " + subject.toUtf8() + "\r\n");
              socket.write("\r\n");
              socket.write(corps.toUtf8() + "\r\n");
              socket.write(".\r\n");
              if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
                  qDebug() << "Échec d'envoi des données du mail:" << socket.errorString();
                  return;
              }
              qDebug() << socket.readAll(); // Afficher la réponse après l'envoi des données du mail

              // Envoi de la commande QUIT
              socket.write("QUIT\r\n");
              if (!socket.waitForBytesWritten()) {
                  qDebug() << "Échec d'envoi de la commande QUIT:" << socket.errorString();
                  return;
              }

              // Fermeture de la connexion
              socket.close();
              QMessageBox::information(this, "Succès", "L'email a été envoyé avec succès à " + destinataire);






}

void MainWindow::on_t_3_clicked()
{
    projet p;
    QSqlQueryModel* model = p.trierParID();  // Appel de la fonction de tri par ID

    if (model->rowCount() > 0) {
        ui->tableView->setModel(model);
        ui->tableView->setSortingEnabled(true);  // Permet de trier par colonnes
    } else {
        QMessageBox::warning(this, "Résultat", "Aucun projet trouvé.");
    }
}

void MainWindow::on_t_4_clicked()
{
    projet p;
      QSqlQueryModel* model = p.trierParStatut();  // Appel de la fonction de tri

      if (model->rowCount() > 0) {
          ui->tableView->setModel(model);
          ui->tableView->setSortingEnabled(true);  // Permet de trier par colonnes
      } else {
          QMessageBox::warning(this, "Résultat", "Aucun projet trouvé.");
      }
}

