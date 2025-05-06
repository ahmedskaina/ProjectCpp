#include "dialog_stats.h"
#include "ui_dialog_stats.h"
#include "employe.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDebug>

Dialog_stats::Dialog_stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_stats)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries;

    QList<qreal> valeurs = stat();
    QList<QString> noms = stat_nom();

    if (valeurs.isEmpty()) {
        qDebug() << "Aucune donnée à afficher !";
        return;
    }

    for(int i = 0; i < valeurs.size(); i++)
    {
        QPieSlice *slice = series->append(noms[i] + " (" + QString::number(valeurs[i]) + ")", valeurs[i]);
        slice->setLabelVisible(true);
        slice->setBrush(QColor::fromHsv((i * 60) % 360, 255, 200));
    }

    QChart *chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Statistiques des employés par numéro");

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    // ✅ Ajout au layout pour assurer l'affichage
    if (ui->Frame1->layout()) {
        ui->Frame1->layout()->addWidget(chartview);
    } else {
        qDebug() << "Erreur : Pas de layout trouvé pour Frame1 !";
    }
}

Dialog_stats::~Dialog_stats()
{
    delete ui;
}

// 📌 Récupération des nombres d'employés
QList<qreal> Dialog_stats::stat()
{
    QList<qreal> list;
    QSqlQuery query;
    query.prepare("SELECT NOM_EMPLOYEE, SUM(NUMERO_EMPLOYEE) AS total FROM employee GROUP BY NOM_EMPLOYEE ORDER BY total DESC");

    if (!query.exec()) {
        qDebug() << "Erreur SQL (stat) :" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        list.append(query.value(1).toInt());
        qDebug() << "Nombre employé :" << query.value(1).toInt();
    }

    return list;
}

// 📌 Récupération des noms des employés
QList<QString> Dialog_stats::stat_nom()
{
    QList<QString> list;
    QSqlQuery query;
    query.prepare("SELECT NOM_EMPLOYEE, SUM(NUMERO_EMPLOYEE) AS total FROM employee GROUP BY NOM_EMPLOYEE ORDER BY total DESC");

    if (!query.exec()) {
        qDebug() << "Erreur SQL (stat_nom) :" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        list.append(query.value(0).toString());
        qDebug() << "Nom employé :" << query.value(0).toString();
    }

    return list;
}
