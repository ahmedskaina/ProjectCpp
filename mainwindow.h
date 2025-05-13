#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <projet.h>
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
#include "qrcodegen.hpp"  // Inclure la bibliothèque qrcodegen
#include "serialcommunication.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void listprojet();

private slots:
    void on_btnPredire_clicked();
    void on_ajout_clicked();
    void clearFields() ;

    void on_afficher_clicked();

    void on_modif_clicked();

    void on_supprimer_clicked();

    void on_rech_clicked();

    void on_t_clicked();

    void on_p_clicked();

    void on_statistq_clicked();

    void on_t_2_clicked();
    void on_histo_clicked();
      void afficherHistorique();

      void on_sendMail_clicked();

      void on_t_3_clicked();

      void on_t_4_clicked();

private:
    Ui::MainWindow *ui;
      projet Ptmp;
      projet p;
      QSqlQueryModel *model;  // le modèle pour tableView
      SerialCommunication *serial;

};
#endif // MAINWINDOW_H
