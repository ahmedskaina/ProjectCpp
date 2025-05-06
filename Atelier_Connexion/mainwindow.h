#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"qrcodeg.h"
#include <QMainWindow>
#include "examen.h"
#include <QtCharts/QLineSeries>
#include <QEvent>
#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QTextDocument>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QScreen>

#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QEvent>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QLabel>
#include <QDate>
#include<dialog_stats.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();






    void on_pb_modifier_2_clicked();

    void on_supprimer_clicked();

    void on_pb_tri_id_clicked();

    void on_pb_tri_nom_clicked();

    void on_pb_pdf_clicked();

    void on_pb_Rech_clicked();

    void on_statss_clicked();
    void on_QRgenerate_clicked();
    void updateQRImage();
    void setScale(int);
    void on_ButtonSave_clicked();
    void on_sBoxScale_3_valueChanged(int arg1);
    void on_pTextEditQRText_3_textChanged();
    void on_pButtonQuit_2_clicked();

private:
    void onTableSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    Ui::MainWindow *ui; // This automatically includes tab_Examen

    QStandardItemModel *model;
    QLineEdit* le_confirm;
    bool successfulEncoding;
    int encodeImageSize;
    QPoint lastPos;
    CQR_Encode qrEncode;
    void load_services();
    void load_services_name(QString type);
protected:
    void closeEvent(QCloseEvent *);
    bool eventFilter( QObject * object, QEvent * event );
};

#endif // MAINWINDOW_H
