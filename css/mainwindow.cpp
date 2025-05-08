#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QPainter>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Equipement eq;
    ui->setupUi(this);

    for (int column = 0; column < eq.afficher()->columnCount()-1; ++column)
    {
        QString columnName = eq.afficher()->headerData(column, Qt::Horizontal).toString();
        ui->sortingBy->addItem(columnName, QVariant(column));
    }
    ui->sortingMode->addItem("Ascending", QVariant(Qt::AscendingOrder));
    ui->sortingMode->addItem("Descending", QVariant(Qt::DescendingOrder));
    connect(ui->sortingBy, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [this]() {
        applySorting(ui->tableViewEquipement, ui->sortingBy, ui->sortingMode);
    });
    connect(ui->sortingMode, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [this]() {
        applySorting(ui->tableViewEquipement, ui->sortingBy, ui->sortingMode);
    });
    filterModel->setSourceModel(eq.afficher());
    filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
       filterModel->setFilterKeyColumn(-1); // Apply filter to all columns
      ui->tableViewEquipement->setModel(filterModel);
      connect(ui->search, &QLineEdit::textChanged, this, [this](const QString &text)
      {

             filterModel->setFilterWildcard(text);


         });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonAdd_clicked()
{
    // Retrieve input values from UI
    QString nom = ui->lineEditNom->text();
    int quantite = ui->spinBoxQuantite->value();
    double prixUnitaire = ui->doubleSpinBoxPrixUnitaire->value();
    QString description = ui->lineEditDescription->text();
    QString imagePath = ui->imageButton->text();  // Get the image path from the button

    // Validate input fields
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Nom cannot be empty!");
        return;
    }

    // Create Equipement object with image path
    Equipement eq(nom, quantite, prixUnitaire, description, imagePath);

    // Attempt to add the equipment to the database
    if (eq.ajouter()) {
        QMessageBox::information(this, "Success", "Equipement added successfully.");
        ui->tableViewEquipement->setModel(filterModel);(eq.afficher()); // Refresh table
    } else {
        QMessageBox::critical(this, "Error", "Failed to add Equipement.");
    }
}

void MainWindow::on_buttonUpdate_clicked()
{
    // Retrieve the selected ID from the hidden property
    QVariant idVariant = ui->buttonUpdate->property("selectedID");
    if (!idVariant.isValid()) {
        QMessageBox::warning(this, "Update Error", "Please select a record to update.");
        return;
    }

    int id = idVariant.toInt();  // Convert stored ID to int

    // Get updated values from input fields
    QString nom = ui->lineEditNom->text();
    int quantite = ui->spinBoxQuantite->value();
    double prixUnitaire = ui->doubleSpinBoxPrixUnitaire->value();
    QString description = ui->lineEditDescription->text();
    QString imagePath = ui->imageButton->text();  // Get the image path from the button

    // Validate inputs
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Nom cannot be empty!");
        return;
    }

    // Create an Equipement object
    Equipement eq(nom, quantite, prixUnitaire, description, imagePath);

    // Attempt to update the record
    if (eq.modifier(id)) {
        QMessageBox::information(this, "Success", "Equipement updated successfully.");
        ui->tableViewEquipement->setModel(filterModel);(eq.afficher()); // Refresh the table
    } else {
        QMessageBox::critical(this, "Error", "Failed to update Equipement.");
    }
}



void MainWindow::on_tableViewEquipement_clicked(const QModelIndex &index)
{
    // Get selected row index
    int row = index.row();

    // Extract data from the selected row
    QString id = ui->tableViewEquipement->model()->index(row, 0).data().toString();
    QString nom = ui->tableViewEquipement->model()->index(row, 1).data().toString();
    int quantite = ui->tableViewEquipement->model()->index(row, 2).data().toInt();
    double prixUnitaire = ui->tableViewEquipement->model()->index(row, 3).data().toDouble();
    QString description = ui->tableViewEquipement->model()->index(row, 4).data().toString();

    // Fill input fields with selected row data
    ui->lineEditNom->setText(nom);
    ui->spinBoxQuantite->setValue(quantite);
    ui->doubleSpinBoxPrixUnitaire->setValue(prixUnitaire);
    ui->lineEditDescription->setText(description);

    // Store the selected ID in a hidden property for updating
    ui->buttonUpdate->setProperty("selectedID", id);
}


void MainWindow::on_buttonDelete_clicked()
{
    // Get selected row
    QModelIndexList selectedRows = ui->tableViewEquipement->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Delete Error", "Please select an Equipement to delete.");
        return;
    }

    int id = ui->tableViewEquipement->model()->index(selectedRows.first().row(), 0).data().toInt();

    // Confirm deletion
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion",
                                  "Are you sure you want to delete this Equipement?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Equipement eq;
        if (eq.supprimer(id)) {
            QMessageBox::information(this, "Success", "Equipement deleted successfully.");
            ui->tableViewEquipement->setModel(filterModel);(eq.afficher()); // Refresh table
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete Equipement.");
        }
    }
}


void MainWindow::on_imageButton_clicked()
{
    // Open a file dialog to choose the image
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!imagePath.isEmpty()) {
        // Set the path on the button (you can store it elsewhere if needed)
        ui->imageButton->setText(imagePath);  // Display the image path on the button

        // Now you can store the image path into the Equipement object when adding/updating
        // This will be used in the ajouter or modifier methods
    }
}
void MainWindow::applySorting(QTableView* tableView, QComboBox* sortingBy, QComboBox* sortingMode)
{
    int sortColumn = sortingBy->currentData().toInt(); // Retrieve the column index
    Qt::SortOrder sortOrder = static_cast<Qt::SortOrder>(sortingMode->currentData().toInt()); // Retrieve the sort order
    tableView->model()->sort(sortColumn, sortOrder); // Apply sorting to the model
}


void MainWindow::on_buttonPDF_clicked()
{

    Equipement eq;
    eq.extractPDFEquipement();
}

void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    Equipement eq;
    ui->horizontalLayout_2->addWidget(eq.createCategoryDistributionChart());
    ui->horizontalLayout_3 ->addWidget(eq.createQuantityDistributionChart());
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    // Get the text from the QTextEdit input
    QString inputText = ui->inputTextEdit->toPlainText();

    // Check if input text is empty
    if (inputText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter some text.");
        return;
    }

    // Clear the input field
    ui->inputTextEdit->clear();

    // Set the request URL for the Gemini API
    QUrl url("https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key=AIzaSyD6jTSmRNnB4sodctwc8QR8ZMGTV-gg1yA");
    QNetworkRequest request(url);

    // Set the content type to JSON
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Prepare the correct JSON data structure for Gemini API
    QJsonObject content;
    QJsonObject textPart;
    textPart["text"] = inputText;
    QJsonArray parts;
    parts.append(textPart);
    content["parts"] = parts;

    QJsonArray contents;
    contents.append(content);

    QJsonObject json;
    json["contents"] = contents;

    // Convert the JSON object to a JSON document and then to a QByteArray
    QJsonDocument jsonDoc(json);
    QByteArray data = jsonDoc.toJson();

    // Create a network manager and send the POST request with the JSON data
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    QNetworkReply *reply = networkManager->post(request, data);

    // Handle the reply once it is finished
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            // Display detailed error information
            ui->inputTextEdit->setPlainText("Error: " + reply->errorString() + "\nResponse: " + reply->readAll());
        } else {
            // Parse and display the response
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();

            // Extract the generated text from the response
            QString generatedText;
            if (jsonObject.contains("candidates")) {
                QJsonArray candidates = jsonObject["candidates"].toArray();
                if (!candidates.isEmpty()) {
                    QJsonObject candidate = candidates[0].toObject();
                    if (candidate.contains("content")) {
                        QJsonObject content = candidate["content"].toObject();
                        if (content.contains("parts")) {
                            QJsonArray parts = content["parts"].toArray();
                            if (!parts.isEmpty()) {
                                generatedText = parts[0].toObject()["text"].toString();
                            }
                        }
                    }
                }
            }

            if (generatedText.isEmpty()) {
                generatedText = "No response generated or couldn't parse response.\nFull response:\n" + responseData;
            }

            ui->inputTextEdit->setPlainText(generatedText);
        }
        reply->deleteLater();  // Clean up the reply object
    });
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

