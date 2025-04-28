#include "gestion_client.h"
#include "clients.h"
#include "ui_gestion_client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QIntValidator>
#include<QMessageBox>
#include <iostream>
#include <string>
#include<QPropertyAnimation>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QByteArray>
#include <QSqlQuery>
#include <QTime>
#include <QNetworkAccessManager>
gestion_client::gestion_client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion_client)
{
    ui->setupUi(this);
    QValidator *validatorInt = new QIntValidator(1, 99999999, this);
    ui->lineEdit_id->setValidator(validatorInt);

    ui->lineEdit_id_sup->setValidator(validatorInt);
    ui->lineEdit_recherche->setValidator(validatorInt);
}

gestion_client::~gestion_client()
{
    delete ui;
}

void gestion_client::on_pushButton_ajouter_clicked()
{
    int ID=ui->lineEdit_id->text().toInt();
    QString nom_client=ui->lineEdit_nom->text();
    QString prenom_client=ui->lineEdit_prenom->text();
    QString adress_client=ui->lineEdit_adress->text();
    QString tlf_client=ui->lineEdit_tlf->text();
    QDate datea=ui->datea->date();


    int x=0;




    if (nom_client=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                              QObject::tr("Nom n'est pas vide"), QMessageBox::Ok);
        x++;
    }
    else if (prenom_client=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                              QObject::tr("prenom n'est pas vide"), QMessageBox::Ok);
        x++;
    }





    else if(x==0)
    {
        clients Sp(ID,nom_client,prenom_client,adress_client,tlf_client,datea);
        bool toTest =Sp.Ajouter();
        if(toTest)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajout client"),
                                     QObject::tr(" ajout client avec succès"), QMessageBox::Ok);
            ui->tab_client->setModel(Sp.afficher());
        }
        ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_tlf->clear();
        ui->lineEdit_adress->clear();
        ui->lineEdit_tlf->clear();

        ui->datea->setDate(QDate::currentDate());


    }
}


void gestion_client::on_pushButton_modifier_clicked()
{
    int ID = ui->lineEdit_id->text().toInt();
    QString nom_client = ui->lineEdit_nom->text();
    QString prenom_client = ui->lineEdit_prenom->text();
    QString adress_client = ui->lineEdit_adress->text();
    QString tlf_client = ui->lineEdit_tlf->text();
    QDate datea=ui->datea->date();

    int x = 0;

    if(nom_client.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                              QObject::tr("Le nom ne doit pas être vide"), QMessageBox::Ok);
        x++;
    }
    else if(prenom_client.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("WARNING"),
                              QObject::tr("Le prénom ne doit pas être vide"), QMessageBox::Ok);
        x++;
    }

    if(x == 0)
    {
        // Create a client object with the new data
        clients client(ID, nom_client, prenom_client, adress_client, tlf_client,datea);
        bool toTest = client.modifier();
        if(toTest)
        {
            QMessageBox::information(nullptr, QObject::tr("Modification client"),
                                     QObject::tr("Client modifié avec succès"), QMessageBox::Ok);
            ui->tab_client->setModel(client.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modification client"),
                                  QObject::tr("Échec de la modification du client"), QMessageBox::Ok);
        }

        // Clear the fields after modification
        ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_adress->clear();
        ui->lineEdit_tlf->clear();
        ui->datea->setDate(QDate::currentDate());

    }
}



void gestion_client::on_pb_supp_clicked()
{
    clients Sp;
    Sp.set_ID_CLIENTS(ui->lineEdit_id_sup->text().toInt());
    bool test=Sp.supprimer(Sp.get_ID_CLIENTS());
    QMessageBox msgbox;

    if (test)
    {
        msgbox.setText("Suppression avec succes");
        ui->tab_client->setModel(Sp.afficher());
    }
    else
        msgbox.setText("failed");
    msgbox.exec();
    ui->lineEdit_id_sup->clear();
}


void gestion_client::on_pb_recherche_clicked()
{
    clients Sp;
    Sp.set_ID_CLIENTS(ui->lineEdit_recherche->text().toInt());
    bool test=Sp.RechercheClientParID(Sp.get_ID_CLIENTS());
    QMessageBox msgbox;

    if (test)
    {
        msgbox.setText("ID existe");
        ui->tab_client->setModel(Sp.afficher());
    }
    else
        msgbox.setText("ID n'existe pas");
    msgbox.exec();
    ui->lineEdit_recherche->clear();
}


void gestion_client::on_radioButton_id_clicked()
{
    clients *Sp = new clients();
    ui->tab_client->setModel(Sp->tri_ID());
}


void gestion_client::on_pushButton_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_client->model()->rowCount();
    const int columnCount =ui->tab_client->model()->columnCount();


    out <<  "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("eleve")
        <<  "</head>\n"
           "<body bgcolor= #fffde0  link=#fffde0>\n"

           "<h1 >Liste des clients</h1> <br></br> <br> </br>  "

           "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#fffde0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_client->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_client->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";
    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_client->isColumnHidden(column)) {
                QString data = ui->tab_client->model()->data(ui->tab_client->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
           "</body>\n"
           "</html>\n";



    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);


    //QTextDocument document;
    //document.setHtml(html);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("mypdffile.pdf");
    document->print(&printer);
}


void gestion_client::on_pushButton_stats_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENT where ID_CLIENTS < 10 ");
    float tarif1=model->rowCount();
    model->setQuery("select * from CLIENTS where ID_CLIENTS  between 100 and 1500 ");
    float tarif2=model->rowCount();
    model->setQuery("select * from CLIENTS where ID_CLIENTS >1500 ");
    float tarif3=model->rowCount();
    float total=tarif1+tarif2+tarif3;
    QString a=QString("moins de 10 CLIENTS "+QString::number((tarif1*100)/total,'f',2)+"%" );
    QString b=QString("entre 10 et 15 CLIENTS "+QString::number((tarif2*100)/total,'f',2)+"%" );
    QString c=QString("+15 CLIENTS "+QString::number((tarif3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tarif1);
    series->append(b,tarif2);
    series->append(c,tarif3);
    if (tarif1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tarif2!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(tarif3!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par CLIENTS :Nombre Des CLIENTS "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();


    //end statistique
}


void gestion_client::envoyerSMS(const QString &destinataire, const QString &message)
{
    // SID et auth token de Twilio
    QString sid = "ACd6bd850d769a9a64d5878779e8df3287";
    QString authToken = "5886babdd060c1a44f37a7733c28a224";

    // Construire l'URL de l'API Twilio
    QString url = "https://api.twilio.com/2010-04-01/Accounts/" + sid + "/Messages.json";

    // Créer le gestionnaire de réseau
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
   //networkAccessManager->setNetworkAccessible(QNetworkAccessManager::Accessible); // Définir l'accessibilité du réseau
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    // Construire les données de la requête
    QByteArray postData;
    postData.append("To=" + destinataire.toUtf8());
    postData.append("&From=+19599911226");
    postData.append("&Body=" + message.toUtf8());

    // Créer la requête HTTP
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(sid).arg(authToken).toUtf8()).toBase64());


    // Envoyer la requête
    networkAccessManager->post(request, postData);

    // Afficher un message de succès
    QMessageBox::information(this, "Envoi SMS", "Le SMS a été envoyé avec succès.");
}

void gestion_client::on_pushButton_2_clicked()
{

    QString destinataire = "+21651560317"; // Numéro de téléphone du destinataire
    QString message = ui->contenu->toPlainText(); // Récupérer le contenu du champ de texte

    envoyerSMS(destinataire, message);



}


void gestion_client::on_calendarWidget_clicked(const QDate &date)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE DATEA = :datea");
    query.bindValue(":datea", date); // Qt gère automatiquement le format

    if (!query.exec()) {
         QMessageBox::warning(this, "Erreur", "Impossible de filtrer les clients par date.");
        return;
    }

    model->setQuery(query);
    ui->tab_client->setModel(model);
}

