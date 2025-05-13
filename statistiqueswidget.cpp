// StatistiquesWidget.cpp
#include "StatistiquesWidget.h"
#include <QPainter>
#include <QMap>
#include <QRandomGenerator>

StatistiquesWidget::StatistiquesWidget(QSqlQueryModel* model, QWidget *parent)
    : QWidget(parent), model(model)
{
    setWindowTitle("Statistiques des projets par statut");
    resize(800, 600);  // Taille de la fenêtre
}

void StatistiquesWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    // Calculer le nombre de projets par statut
    QMap<QString, int> statutCount;
    for (int row = 0; row < model->rowCount(); ++row) {
        QString statut = model->data(model->index(row, 6)).toString(); // colonne 6 (statut)

        if (!statut.isEmpty()) {
            statutCount[statut]++;
        }
    }

    // Calcul des pourcentages
    int totalCount = model->rowCount();
    QMap<QString, qreal> statutPercentages;
    for (auto it = statutCount.begin(); it != statutCount.end(); ++it) {
        qreal percentage = (static_cast<qreal>(it.value()) / totalCount) * 100.0;
        statutPercentages[it.key()] = percentage;
    }

    // Variables de positionnement pour le graphique
    int xCenter = width() / 2;
    int yCenter = height() / 2;
    int radius = 200;  // Rayon du graphique
    int startAngle = 0;

    // Dessiner chaque secteur pour chaque statut
    for (auto it = statutPercentages.begin(); it != statutPercentages.end(); ++it) {
        qreal percentage = it.value();
        int spanAngle = (percentage / 100) * 360;

        // Définir une couleur pour chaque secteur
        QColor color = QColor::fromHsvF(qrand() % 360 / 360.0, 0.7, 0.7);  // Couleur aléatoire
        painter.setBrush(color);

        // Dessiner le secteur
        painter.drawPie(xCenter - radius, yCenter - radius, 2 * radius, 2 * radius, startAngle * 16, spanAngle * 16);
        startAngle += spanAngle;
    }

    // Dessiner les légendes
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));

    int legendX = 30;
    int legendY = 30;
    for (auto it = statutPercentages.begin(); it != statutPercentages.end(); ++it) {
        QColor color = QColor::fromHsvF(qrand() % 360 / 360.0, 0.7, 0.7);  // Couleur pour chaque secteur
        painter.setBrush(color);
        painter.drawRect(legendX, legendY, 15, 15);
        painter.drawText(legendX + 20, legendY + 12, it.key() + " (" + QString::number(it.value(), 'f', 1) + "%)");
        legendY += 25;
    }
}
