/********************************************************************************
** Form generated from reading UI file 'loginn.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINN_H
#define UI_LOGINN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Loginn
{
public:
    QLineEdit *lineEditEmail;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditMdp;
    QPushButton *pushButton;

    void setupUi(QDialog *Loginn)
    {
        if (Loginn->objectName().isEmpty())
            Loginn->setObjectName("Loginn");
        Loginn->resize(1021, 670);
        lineEditEmail = new QLineEdit(Loginn);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(410, 200, 171, 31));
        label = new QLabel(Loginn);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 210, 71, 20));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(Loginn);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 310, 141, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        lineEditMdp = new QLineEdit(Loginn);
        lineEditMdp->setObjectName("lineEditMdp");
        lineEditMdp->setGeometry(QRect(410, 320, 171, 31));
        pushButton = new QPushButton(Loginn);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 430, 111, 31));

        retranslateUi(Loginn);

        QMetaObject::connectSlotsByName(Loginn);
    } // setupUi

    void retranslateUi(QDialog *Loginn)
    {
        Loginn->setWindowTitle(QCoreApplication::translate("Loginn", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Loginn", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("Loginn", "password", nullptr));
        pushButton->setText(QCoreApplication::translate("Loginn", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginn: public Ui_Loginn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINN_H
