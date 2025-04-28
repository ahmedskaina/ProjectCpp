#ifndef GESTION_CLIENT_H
#define GESTION_CLIENT_H
// geters ou seters ou fctionnetpublic
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class gestion_client;
}
QT_END_NAMESPACE

class gestion_client : public QMainWindow
{
    Q_OBJECT

public:
    gestion_client(QWidget *parent = nullptr);
    ~gestion_client();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_modifier_clicked();

    void on_pb_supp_clicked();

    void on_pb_recherche_clicked();

    void on_radioButton_id_clicked();

    void on_pushButton_clicked();

    void on_pushButton_stats_clicked();

    void on_pushButton_2_clicked();
    void  envoyerSMS(const QString &destinataire, const QString &message);

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::gestion_client *ui;
};
#endif // GESTION_CLIENT_H
