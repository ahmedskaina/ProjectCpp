/********************************************************************************
** Form generated from reading UI file 'recorder.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDER_H
#define UI_RECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recorder
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *OptionPushButton;

    void setupUi(QDialog *recorder)
    {
        if (recorder->objectName().isEmpty())
            recorder->setObjectName("recorder");
        recorder->resize(1125, 737);
        scrollArea = new QScrollArea(recorder);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(200, 210, 681, 381));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 679, 379));
        scrollArea->setWidget(scrollAreaWidgetContents);
        OptionPushButton = new QPushButton(recorder);
        OptionPushButton->setObjectName("OptionPushButton");
        OptionPushButton->setGeometry(QRect(490, 160, 111, 31));
        OptionPushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:rgb(169, 185, 255);\n"
"font-size:15px;\n"
"font: 12pt \"Mongolian Baiti\";\n"
"border-radius:10px;\n"
"}\n"
"QPushButton:hover {\n"
"	\n"
"	background-color:rgb(185, 198, 255);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:rgb(185, 198, 255);\n"
"}\n"
""));

        retranslateUi(recorder);

        QMetaObject::connectSlotsByName(recorder);
    } // setupUi

    void retranslateUi(QDialog *recorder)
    {
        recorder->setWindowTitle(QCoreApplication::translate("recorder", "Dialog", nullptr));
        OptionPushButton->setText(QCoreApplication::translate("recorder", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recorder: public Ui_recorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDER_H
