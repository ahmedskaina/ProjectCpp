#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QSqlQuery>
#include <QSqlError>
#include <QDesktopServices>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChart>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>


class Equipement
{
public:
    Equipement();
    Equipement(QString NOM, int QUANTITE, double PRIX_UNITAIRE, QString DESCRIPTION,QString IMAGE);

    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* afficher();

    // Getters
    int getId() const { return ID_EQUIPEMENT; }
    QString getNom() const { return NOM; }
    int getQuantite() const { return QUANTITE; }
    double getPrixUnitaire() const { return PRIX_UNITAIRE; }
    QString getDescription() const { return DESCRIPTION; }
     QString getImage() const { return IMAGE; }

    // Setters
    void setId(int id) { ID_EQUIPEMENT = id; }
    void setNom(QString nom) { NOM = nom; }
    void setQuantite(int quantite) { QUANTITE = quantite; }
    void setPrixUnitaire(double prix) { PRIX_UNITAIRE = prix; }
    void setDescription(QString description) { DESCRIPTION = description; }
    void setImage(QString image)  {IMAGE = image; }
    QChartView* createQuantityDistributionChart();
    QChartView* createCategoryDistributionChart();
    void  extractPDFEquipement();

private:
    int ID_EQUIPEMENT;
    QString NOM;
    int QUANTITE;
    double PRIX_UNITAIRE;
    QString DESCRIPTION;
    QString IMAGE;
};

#endif // EQUIPEMENT_H
