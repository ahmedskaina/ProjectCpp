#include "loginn.h"
#include "ui_loginn.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

Loginn::Loginn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loginn)
{
    ui->setupUi(this);

    // 🔥 Masquer le mot de passe avec des étoiles
    ui->lineEditMdp->setEchoMode(QLineEdit::Password);
}

Loginn::~Loginn()
{
    delete ui;
}

void Loginn::on_pushButton_clicked()
{
    QString email = ui->lineEditEmail->text();
    QString mdp = ui->lineEditMdp->text();

    if (email.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    if (verifierUtilisateur(email, mdp)) {
        QMessageBox::information(this, "Succès", "Connexion réussie !");

        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();

        this->close();  // Fermer la fenêtre de connexion
    } else {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect.");
    }
}

bool Loginn::verifierUtilisateur(const QString &email, const QString &mdp)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM employee WHERE email_employee = :email AND password_employee = :mdp");
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    if (query.exec() && query.next()) {
        return true;  // Utilisateur trouvé
    }
    return false;  // Échec de connexion
}
