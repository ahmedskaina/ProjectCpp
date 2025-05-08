#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QTableView>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void applySorting(QTableView* tableView, QComboBox* sortingBy, QComboBox* sortingMode);
    void generateQRCode(const QString &data);

private slots:
    void on_buttonAdd_clicked();

    void on_buttonUpdate_clicked();

    void on_tableViewEquipement_clicked(const QModelIndex &index);

    void on_buttonDelete_clicked();

    void on_imageButton_clicked();


    void on_buttonPDF_clicked();

    void on_Back_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
      QSortFilterProxyModel *filterModel = new QSortFilterProxyModel(this);
};
#endif // MAINWINDOW_H
