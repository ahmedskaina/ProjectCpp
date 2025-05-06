#ifndef DIALOG_STATS_H
#define DIALOG_STATS_H
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QDialog>
#include <QWidget>
#include <QList>

namespace Ui {
class Dialog_stats;
}

class Dialog_stats : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_stats(QWidget *parent = nullptr);
    ~Dialog_stats();

private slots:


private:
    Ui::Dialog_stats *ui;
    QList<qreal> stat();
    QList <QString> stat_nom();

};

#endif // DIALOG_STATS_H
