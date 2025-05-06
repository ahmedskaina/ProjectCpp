/********************************************************************************
** Form generated from reading UI file 'dialog_stats.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STATS_H
#define UI_DIALOG_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_stats
{
public:
    QFrame *Frame1;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *Dialog_stats)
    {
        if (Dialog_stats->objectName().isEmpty())
            Dialog_stats->setObjectName("Dialog_stats");
        Dialog_stats->resize(1204, 739);
        Frame1 = new QFrame(Dialog_stats);
        Frame1->setObjectName("Frame1");
        Frame1->setGeometry(QRect(70, 90, 1031, 511));
        horizontalLayout = new QHBoxLayout(Frame1);
        horizontalLayout->setObjectName("horizontalLayout");

        retranslateUi(Dialog_stats);

        QMetaObject::connectSlotsByName(Dialog_stats);
    } // setupUi

    void retranslateUi(QDialog *Dialog_stats)
    {
        Dialog_stats->setWindowTitle(QCoreApplication::translate("Dialog_stats", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_stats: public Ui_Dialog_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STATS_H
