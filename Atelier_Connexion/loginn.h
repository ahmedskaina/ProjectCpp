#ifndef LOGINN_H
#define LOGINN_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"

namespace Ui {
class Loginn;  // 🔥 Mise à jour du nom ici
}

class Loginn : public QDialog
{
    Q_OBJECT

public:
    explicit Loginn(QWidget *parent = nullptr);
    ~Loginn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Loginn *ui;  // 🔥 Mise à jour ici aussi

    bool verifierUtilisateur(const QString &email, const QString &mdp);
};

#endif // LOGINN_H
