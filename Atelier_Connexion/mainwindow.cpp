#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QStackedWidget>
#include <QPlainTextEdit>
#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QScreen>
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QFile>
#include <QScrollBar>
#include <QSettings>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QCloseEvent>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrintDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>

#include "employe.h"
#include "dialog_stats.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Employe E;
 ui->le_password->setEchoMode(QLineEdit::Password);

    ui->tab_employe->setModel(E.afficher());
     ui->tab_employe_2->setModel(E.afficher());
       ui->tab_employe_3->setModel(E.afficher());
    ui->tab_rech->setModel(E.afficher());

    // Ajout de validation pour ID examen
    ui->le_cin->setValidator(new QIntValidator(0, 99999999, this));
   ui->le_cin_2->setValidator(new QIntValidator(0, 99999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    // Récupération des données
    int cin = ui->le_cin->text().toInt();  // Change cin to le_cin
    QString nom = ui->le_nom->text();  // Change nom to le_nom
    QString prenom = ui->le_prenom->text();  // Change prenom to le_prenom
    int numero = ui->le_numero->text().toInt();  // Change numero to le_numero
    QString email = ui->le_email->text();  // Change email to le_email
    QString password = ui->le_password->text();  // Change password to le_password

    // Vérification des champs vides
    if (ui->le_cin->text().isEmpty() || ui->le_nom->text().isEmpty() ||
        ui->le_prenom->text().isEmpty() || ui->le_numero->text().isEmpty() ||
        ui->le_email->text().isEmpty() || ui->le_password->text().isEmpty()) {  // Change password to le_password
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    // Vérification de l'email
    if (!email.contains("@") || !email.contains(".")) {
        QMessageBox::warning(this, tr("Email invalide"),
                             tr("Veuillez entrer une adresse email valide."), QMessageBox::Ok);
        return;
    }

    // Création de l'objet employé
    Employe employe(cin, nom, prenom, numero, email, password);

    // Ajout dans la base de données
    if (employe.ajouter()) {
        ui->tab_employe->setModel(employe.afficher());
        QMessageBox::information(this, tr("Succès"), tr("Employé ajouté avec succès!"));

        // Vider les champs après ajout
        ui->le_cin->clear();  // Change cin to le_cin
        ui->le_nom->clear();  // Change nom to le_nom
        ui->le_prenom->clear();  // Change prenom to le_prenom
        ui->le_numero->clear();  // Change numero to le_numero
        ui->le_email->clear();  // Change email to le_email
        ui->le_password->clear();  // Change password to le_password
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'ajout de l'employé."));
    }
}




void MainWindow::on_pb_modifier_2_clicked()
{
    // Retrieve and convert UI input values
    int cinEmploye = ui->le_cin_2->text().toInt();  // Get the CIN value from the line edit
    QString nomEmploye = ui->le_nom_2->text();  // Get the last name from the line edit
    QString prenomEmploye = ui->le_prenom_2->text();  // Get the first name from the line edit
    int numeroEmploye = ui->le_numero_2->text().toInt();  // Get the phone number from the line edit
    QString emailEmploye = ui->le_email_2->text();  // Get the email from the line edit
    QString passwordEmploye = ui->le_password_2->text();  // Get the password from the line edit

    // Check if any of the necessary fields are empty
    if (nomEmploye.isEmpty() || prenomEmploye.isEmpty() || emailEmploye.isEmpty() || passwordEmploye.isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    // Check if the email format is valid
    if (!emailEmploye.contains("@") || !emailEmploye.contains(".")) {
        QMessageBox::warning(this, tr("Email invalide"),
                             tr("Veuillez entrer une adresse email valide."), QMessageBox::Ok);
        return;
    }

    // Create Employe object
    Employe employe(cinEmploye, nomEmploye, prenomEmploye, numeroEmploye, emailEmploye, passwordEmploye);

    // Call the method to modify the Employe data
    bool test = employe.modifier();

    if (test) {
        // Show success message
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée\nClick Cancel to exit."), QMessageBox::Cancel);

        // Refresh the displayed table or update the UI
        ui->tab_employe->setModel(employe.afficher());  // Assuming afficher() returns a valid QAbstractItemModel
    } else {
        // Show error message if modification fails
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Employé non trouvé ou modification non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_supprimer_clicked()
{
    // Retrieve the ID entered by the user from the input field
    int idExamen = ui->le_id_supp->text().toInt();  // Assuming the input field is le_id_supp

    // Check if the ID is valid (non-zero)
    if (idExamen <= 0) {
        QMessageBox::warning(this, tr("ID invalide"),
                             tr("Veuillez entrer un ID valide pour supprimer l'examen."), QMessageBox::Ok);
        return;
    }

    // Create Examen object
    Employe E;

    // Call the method to delete the exam
    bool test = E.supprimer(idExamen);

    if (test) {
        // If the deletion was successful, immediately refresh the table
        ui->tab_employe_3->setModel(E.afficher());  // Refresh the table with the updated data

        // Show success message
        QMessageBox::information(this, tr("Suppression effectuée"),
                                 tr("employé supprimé avec succès."), QMessageBox::Ok);
    } else {
        // Show error message if the deletion fails
        QMessageBox::critical(this, tr("Erreur"),
                             tr("Erreur lors de la suppression de l'employé."), QMessageBox::Ok);
    }
}

void MainWindow::on_pb_tri_id_clicked()
{
    Employe E;
   QMessageBox::information(nullptr, QObject::tr("Ok"),
                            QObject::tr("tri_id effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_rech->setModel(E.tri_id());
}

void MainWindow::on_pb_tri_nom_clicked()
{
      Employe E;
    QMessageBox::information(nullptr, QObject::tr("Ok"),
                               QObject::tr("tri_nom effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_rech->setModel(E.tri_nom());
}

void MainWindow::on_pb_pdf_clicked()
{
    Employe E ;
    bool test=false;
    test=E.genererPDF();
    if(test)

        {
        ui->tab_rech->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("créé"),

                            QObject::tr(" PDF créé.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else

        {

            QMessageBox::critical(nullptr, QObject::tr("non créé"),

                        QObject::tr("PDF non créé !.\n"

                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void MainWindow::on_pb_Rech_clicked()
{
    Employe E;
    QString nom_eq = ui->rech_nom->text();


       ui->tab_rech->setModel(E.recherche(nom_eq));
}

void MainWindow::on_statss_clicked()
{
    Dialog_stats *dialog;
        dialog=new Dialog_stats(this);
        dialog->show();
}

void MainWindow::on_QRgenerate_clicked()
{
ui->scrollArea_6->installEventFilter(this);//est une méthode qui permet d'installer un filtre d'événements sur cet objet.
    QSettings ini( "", QSettings::IniFormat );//utilisée pour stocker les paramètres de l'application en utilisant différents formats de stockage
    ui->sBoxScale_3->setValue( ini.value( ui->sBoxScale_3->objectName(), 4 ).toInt() );
    restoreState( ini.value( "State" ).toByteArray() );
    restoreGeometry( ini.value( "Geometry" ).toByteArray() );
//pour restaurer l'état et la géométrie d'une fenêtre à partir des valeurs enregistrées dans un fichier de configuration.
    setScale( ui->sBoxScale_3->value() );
    updateQRImage();
}
void MainWindow::updateQRImage()
{
    int sizeText = ui->pTextEditQRText_3->toPlainText().size();
    ui->labelSizeText_3->setText( QString::number( sizeText ) );

    int levelIndex = 1;
    int versionIndex = 0;
    bool bExtent = true;
    int maskIndex = -1;
    QString encodeString = ui->pTextEditQRText_3->toPlainText();//Elle renvoie le texte brut du widget de l'éditeur de texte, sans aucune mise en forme.

    successfulEncoding = qrEncode.EncodeData( levelIndex, versionIndex, bExtent, maskIndex, encodeString.toUtf8().data() );
    if ( !successfulEncoding )
    {
        ui->image_label_3->clear();
        ui->image_label_3->setText( tr("QR Code...") );
        ui->labelSize_3->clear();
        //ui->ButtonSave->setEnabled( successfulEncoding );
        return;
    }

    int qrImageSize = qrEncode.m_nSymbleSize;

    encodeImageSize = qrImageSize + ( QR_MARGIN * 2 );
    QImage encodeImage( encodeImageSize, encodeImageSize, QImage::Format_Mono );
    //Cette ligne de code calcule la taille de l'image finale qui sera générée pour afficher le code QR en ajoutant la marge de QR_MARGIN pixels de chaque côté de l'image.
    encodeImage.fill( 1 );


    for ( int i = 0; i < qrImageSize; i++ )
        for ( int j = 0; j < qrImageSize; j++ )
            if ( qrEncode.m_byModuleData[i][j] )
                encodeImage.setPixel( i + QR_MARGIN, j + QR_MARGIN, 0 );

    ui->image_label_3->setPixmap( QPixmap::fromImage( encodeImage ) );

    setScale(ui->sBoxScale_3->value());
    //ui->ButtonSave->setEnabled( successfulEncoding );
}
void MainWindow::setScale(int scale)
{
    if ( successfulEncoding )
    {
        int scale_size = encodeImageSize * scale;

        const QPixmap scale_image = ui->image_label_3->pixmap().scaled(scale_size, scale_size);
        ui->image_label_3->setPixmap( scale_image );

        const QString & size_info = QString( "%1x%2" ).arg( scale_size ).arg( scale_size );
        ui->labelSize_3->setText( size_info );
    }
}



void MainWindow::closeEvent(QCloseEvent *)
{
    QSettings ini( "", QSettings::IniFormat );
    //utilisée pour stocker les paramètres de l'application en utilisant différents formats de stockage
    ini.setValue( ui->sBoxScale_3->objectName(), ui->sBoxScale_3->value() );
    ini.setValue( "State", saveState() );
    ini.setValue( "Geometry", saveGeometry() );

    qApp->quit();
}
bool MainWindow::eventFilter( QObject * object, QEvent * event )
{
    QScrollArea * scrollArea = ui->scrollArea_6;

    if ( object == scrollArea )
    {
        if ( event->type() == QEvent::MouseButtonPress )
        {
            QMouseEvent * mouseEvent = static_cast < QMouseEvent * > ( event );
            if ( mouseEvent->button() == Qt::LeftButton )
            {
                lastPos = mouseEvent->pos();

                if( scrollArea->horizontalScrollBar()->isVisible()
                        || scrollArea->verticalScrollBar()->isVisible() )
                    scrollArea->setCursor( Qt::ClosedHandCursor );
                else
                    scrollArea->setCursor( Qt::ArrowCursor );
            }

        }else if ( event->type() == QEvent::MouseMove )
        {
            QMouseEvent *mouseEvent = static_cast < QMouseEvent * > ( event );

            if ( mouseEvent->buttons() == Qt::LeftButton )
            {
                lastPos -= mouseEvent->pos();

                int hValue = scrollArea->horizontalScrollBar()->value();
                int vValue = scrollArea->verticalScrollBar()->value();

                scrollArea->horizontalScrollBar()->setValue( lastPos.x() + hValue );
                scrollArea->verticalScrollBar()->setValue( lastPos.y() + vValue );

                lastPos = mouseEvent->pos();
            }

        }else if ( event->type() == QEvent::MouseButtonRelease )
            scrollArea->setCursor( Qt::ArrowCursor );
    }

    return QWidget::eventFilter(object, event);
}


void MainWindow::on_ButtonSave_clicked()
{
    const QString & path = QFileDialog::getSaveFileName(this, "", "qrcode");
    if ( path.isNull() )
        return;

    QPixmap pixmap = ui->image_label_3->pixmap(); // Correction ici
    pixmap.save(path);
}


void MainWindow::on_sBoxScale_3_valueChanged(int arg1)
{
    setScale( arg1 );
}

void MainWindow::on_pTextEditQRText_3_textChanged()
{
    updateQRImage();
}

void MainWindow::on_pButtonQuit_2_clicked()
{
      close();
}


