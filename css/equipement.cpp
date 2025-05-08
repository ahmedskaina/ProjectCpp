#include "equipement.h"





Equipement::Equipement() {}

Equipement::Equipement(QString NOM, int QUANTITE, double PRIX_UNITAIRE, QString DESCRIPTION, QString IMAGE)
{
    this->NOM = NOM;
    this->QUANTITE = QUANTITE;
    this->PRIX_UNITAIRE = PRIX_UNITAIRE;
    this->DESCRIPTION = DESCRIPTION;
    this->IMAGE = IMAGE;  // New IMAGE member
}

bool Equipement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENT (NOM, QUANTITE, PRIX_UNITAIRE, DESCRIPTION, IMAGE) "
                  "VALUES (:NOM, :QUANTITE, :PRIX_UNITAIRE, :DESCRIPTION, :IMAGE)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":PRIX_UNITAIRE", PRIX_UNITAIRE);
    query.bindValue(":DESCRIPTION", DESCRIPTION);
    query.bindValue(":IMAGE", IMAGE);  // Bind the image path

    if (!query.exec()) {
        qDebug() << "Error adding equipement:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Equipement::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Equipement WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting Equipement:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Equipement::modifier(int id)
{
    QSqlQuery query;

    // Explicitly cast variables to correct data types
    query.prepare("UPDATE Equipement SET Nom = :nom, Quantite = :quantite, "
                  "Prix_Unitaire = :prixUnitaire, Description = :description, IMAGE = :image "
                  "WHERE ID = :id");

    query.bindValue(":nom", NOM);  // QString
    query.bindValue(":quantite", QVariant(QUANTITE).toInt());  // Ensure int type
    query.bindValue(":prixUnitaire", QVariant(PRIX_UNITAIRE).toDouble()); // Ensure double type
    query.bindValue(":description", DESCRIPTION);  // QString
    query.bindValue(":image", IMAGE);  // New IMAGE field
    query.bindValue(":id", QVariant(id).toInt());  // Ensure ID is bound as an int

    if (!query.exec()) {
        qDebug() << "Error updating Equipement:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Equipement::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPEMENT");
    return model;
}
void Equipement::extractPDFEquipement()
{
    // Execute query to retrieve equipment details
    QSqlQuery query;
    query.prepare("SELECT NOM, QUANTITE, PRIX_UNITAIRE, DESCRIPTION, VALEUR_TOTALE FROM EQUIPEMENT");
    query.exec();

    // Set up the PDF Writer
    QPdfWriter pdf("Equipement_Report.pdf");
    pdf.setPageSize(QPageSize(QPageSize::A0));  // Use A0 size, landscape
    pdf.setPageOrientation(QPageLayout::Orientation::Landscape);
    QPainter painter(&pdf);

    // Set up font for content
    QFont font("Arial", 18);
    painter.setFont(font);

    // Add Title
    QFont titleFont("Arial", 50, QFont::Bold);
    painter.setFont(titleFont);
    QString title = "Equipement Report";
    QRect titleRect = painter.boundingRect(QRect(), Qt::AlignCenter, title);
    int titleX = (pdf.width() - titleRect.width()) / 2 + 200;
    int titleY = 600;
    painter.drawText(titleX, titleY, title);

    // Define table layout parameters
    int y = 3500;  // Starting y-position for rows
    const int yOffset = 500; // Row height
    int columnWidth = 7000;
    int columnSpacing = 1000;

    // Draw Table Header
    painter.setPen(Qt::blue);
    QFont headerFont("Arial", 18, QFont::Bold);
    painter.setFont(headerFont);
    painter.drawText(2000, 3300, "Name");
    painter.drawText(2000 + columnWidth + columnSpacing, 3300, "Quantity");
    painter.drawText(2000 + 2 * (columnWidth + columnSpacing), 3300, "Unit Price");
    painter.drawText(2000 + 3 * (columnWidth + columnSpacing), 3300, "Description");
    painter.drawText(2000 + 4 * (columnWidth + columnSpacing), 3300, "Total Value");

    // Add data rows
    painter.setPen(Qt::black);
    while (query.next()) {
        y += yOffset;

        // Draw each column value
        painter.drawText(2000, y, query.value(0).toString()); // Name
        painter.drawText(2000 + columnWidth + columnSpacing, y, query.value(1).toString()); // Quantity
        painter.drawText(2000 + 2 * (columnWidth + columnSpacing), y, query.value(2).toString()); // Unit Price
        painter.drawText(2000 + 3 * (columnWidth + columnSpacing), y, query.value(3).toString()); // Description
        painter.drawText(2000 + 4 * (columnWidth + columnSpacing), y, query.value(4).toString()); // Total Value

        // Check for page overflow (if the next row will exceed the page)
        if (y > pdf.height() - 500) {
            pdf.newPage();  // Create a new page
            y = 500;  // Reset y-position to top of the new page
        }
    }

    // End painting and save PDF
    painter.end();

    // Open the PDF file
    QDesktopServices::openUrl(QUrl::fromLocalFile("Equipement_Report.pdf"));
}
QChartView* Equipement::createCategoryDistributionChart()
{
    QMap<QString, int> quantityCount;
       QSqlQuery query;

       // Query to count quantity of equipment
       query.prepare("SELECT NOM, QUANTITE FROM EQUIPEMENT");

       if (query.exec()) {
           while (query.next()) {
               QString name = query.value(0).toString();
               int quantity = query.value(1).toInt();
               quantityCount[name] = quantity;
           }
       } else {
           qDebug() << "Query failed:" << query.lastError().text();
           return nullptr;
       }

       // Create the Bar chart
       QVector<QString> names;
       QVector<int> quantities;

       for (auto it = quantityCount.constBegin(); it != quantityCount.constEnd(); ++it) {
           names.push_back(it.key());
           quantities.push_back(it.value());
       }

       QBarSeries *series = new QBarSeries();
       QBarSet *set0 = new QBarSet("Quantity");
       for (int quantity : quantities) {
           *set0 << quantity;
       }
       series->append(set0);

       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Equipment Quantity Distribution");
       chart->setAnimationOptions(QChart::SeriesAnimations);

       QBarCategoryAxis *axisX = new QBarCategoryAxis();
       for (const QString &name : names) {
           axisX->append(name);
       }
       chart->setAxisX(axisX, series);

       QValueAxis *axisY = new QValueAxis();
       axisY->setTitleText("Quantity");
       chart->setAxisY(axisY);

       chart->legend()->hide();

       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       return chartView;
}
QChartView* Equipement::createQuantityDistributionChart()
{
    QMap<QString, int> quantityCount;
    QSqlQuery query;

    // Query to count quantity of equipment
    query.prepare("SELECT NOM, QUANTITE FROM EQUIPEMENT");

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            int quantity = query.value(1).toInt();
            quantityCount[name] = quantity;
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
        return nullptr;
    }

    // Create the Bar chart
    QVector<QString> names;
    QVector<int> quantities;

    for (auto it = quantityCount.constBegin(); it != quantityCount.constEnd(); ++it) {
        names.push_back(it.key());
        quantities.push_back(it.value());
    }

    QBarSeries *series = new QBarSeries();
    QBarSet *set0 = new QBarSet("Quantity");
    for (int quantity : quantities) {
        *set0 << quantity;
    }
    series->append(set0);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Equipment Quantity Distribution");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    for (const QString &name : names) {
        axisX->append(name);
    }
    chart->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantity");
    chart->setAxisY(axisY);

    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
