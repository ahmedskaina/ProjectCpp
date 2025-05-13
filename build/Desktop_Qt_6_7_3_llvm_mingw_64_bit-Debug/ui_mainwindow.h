/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_4;
    QLineEdit *id;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *ajout;
    QPushButton *modif;
    QTableView *tableView;
    QLineEdit *recherche;
    QPushButton *afficher;
    QPushButton *rech;
    QPushButton *supprimer;
    QLineEdit *nom_projet;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *id_2;
    QLineEdit *idrep;
    QComboBox *statut;
    QGroupBox *groupBox_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_18;
    QLabel *label;
    QPushButton *t;
    QPushButton *p;
    QPushButton *statistq;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *stat;
    QPushButton *histo;
    QLabel *qrcodeLabel;
    QPushButton *t_2;
    QPushButton *sendMail;
    QPlainTextEdit *contenu;
    QPlainTextEdit *dest;
    QPushButton *btnPredire;
    QLabel *label_prediction;
    QPushButton *t_3;
    QPushButton *t_4;
    QMenuBar *menubar;
    QMenu *menuprojet;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1326, 757);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(178, 217, 196, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(216, 236, 225, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(89, 108, 98, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(119, 145, 131, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(-60, 0, 1351, 701));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        groupBox_4->setPalette(palette1);
        id = new QLineEdit(groupBox_4);
        id->setObjectName("id");
        id->setGeometry(QRect(70, 100, 321, 41));
        id->setStyleSheet(QString::fromUtf8("#id{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        id->setMaxLength(8);
        dateTimeEdit = new QDateTimeEdit(groupBox_4);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(70, 490, 321, 41));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        dateTimeEdit->setFont(font);
        dateTimeEdit->setStyleSheet(QString::fromUtf8("#dateTimeEdit {\n"
"    background-color: #d7e399; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000; /* Bordure inf\303\251rieure verte fonc\303\251e */\n"
"    padding-bottom: 7px; /* Espace en bas pour l'a\303\251ration */\n"
"    selection-background-color: #92d718; /* Couleur de s\303\251lection verte vive */\n"
"    border-radius: 10px; /* Bordures arrondies */\n"
"}\n"
"\n"
"#dateTimeEdit::drop-down {\n"
"    subcontrol-origin: padding; /* Position d'origine pour le menu d\303\251roulant */\n"
"    subcontrol-position: top right; /* Positionnement en haut \303\240 droite */\n"
"    width: 15px; /* Largeur du menu d\303\251roulant */\n"
"    border-left: 2px solid #1a3137; /* Bordure sombre pour s\303\251parer la zone d\303\251roulante */\n"
"}\n"
"\n"
"#dateTimeEdit::down-arrow {\n"
"    width: 0; /* Suppression de l'ic\303\264ne de fl\303\250che */\n"
"}\n"
"\n"
"#dateTimeEdit QAbstractItemView {\n"
"    color: #1a3137; /* Texte sombre pou"
                        "r le contraste */\n"
"    background-color: #d7e399\n"
"; /* Fond des \303\251l\303\251ments d\303\251roulants */\n"
"}\n"
"\n"
"#dateTimeEdit QLabel[style=\"QComboBox::down-arrow\"] {\n"
"    qproperty-alignment: AlignCenter; /* Alignement centr\303\251 */\n"
"    color: #1a3137; /* Couleur sombre pour le texte */\n"
"}\n"
""));
        dateTimeEdit->setMaximumDateTime(QDateTime(QDate(2050, 12, 31), QTime(23, 59, 59)));
        dateTimeEdit->setMinimumDateTime(QDateTime(QDate(2024, 5, 15), QTime(8, 0, 0)));
        dateTimeEdit->setMinimumDate(QDate(2024, 5, 15));
        dateTimeEdit->setCalendarPopup(false);
        dateTimeEdit->setTimeSpec(Qt::LocalTime);
        ajout = new QPushButton(groupBox_4);
        ajout->setObjectName("ajout");
        ajout->setGeometry(QRect(70, 580, 151, 41));
        QPalette palette2;
        QBrush brush8(QColor(26, 49, 55, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        QBrush brush9(QColor(244, 245, 249, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush9);
        QBrush brush10(QColor(49, 164, 180, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush11(QColor(26, 49, 55, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush12(QColor(26, 49, 55, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush13(QColor(26, 49, 55, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        ajout->setPalette(palette2);
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        ajout->setFont(font1);
        ajout->setStyleSheet(QString::fromUtf8("#ajout {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#ajout:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        modif = new QPushButton(groupBox_4);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(230, 580, 151, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush14(QColor(26, 49, 55, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush15(QColor(26, 49, 55, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush15);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush16(QColor(26, 49, 55, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush16);
#endif
        modif->setPalette(palette3);
        modif->setFont(font1);
        modif->setStyleSheet(QString::fromUtf8("#modif {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#modif:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(410, 130, 731, 241));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f4f5f9; /* Fond du tableau, blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure du tableau avec un bleu sombre */\n"
"    border-radius: 10px; /* Arrondi les coins du tableau */\n"
"    padding: 5px; /* Espace autour du contenu du tableau */\n"
"    gridline-color: #1a3137; /* Couleur des lignes du tableau */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #92d718; /* Fond des en-t\303\252tes de colonnes, vert vif */\n"
"    color: #f4f5f9; /* Texte blanc cass\303\251 pour les en-t\303\252tes */\n"
"    padding: 5px;\n"
"    border: 1px solid #1a3137; /* Bordures des en-t\303\252tes */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    border: 1px solid #1a3137; /* Bordures des cellules */\n"
"    padding: 5px; /* Espace \303\240 l'int\303\251rieur des cellules */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #d7e399; /* Couleur de s\303\251lection des cellules, jaune p\303\242le */\n"
"    color: #1a3137; /* Texte sombre pou"
                        "r la lisibilit\303\251 quand une cellule est s\303\251lectionn\303\251e */\n"
"}\n"
""));
        recherche = new QLineEdit(groupBox_4);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(490, 20, 251, 41));
        recherche->setStyleSheet(QString::fromUtf8("#recherche{\n"
"\n"
" background-color: #f6f6f6;\n"
"    border: 2px solid #1d9000;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    selection-background-color: #1d9000\n"
";\n"
"}"));
        recherche->setMaxLength(8);
        afficher = new QPushButton(groupBox_4);
        afficher->setObjectName("afficher");
        afficher->setGeometry(QRect(1000, 20, 121, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush17(QColor(26, 49, 55, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush17);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush18(QColor(26, 49, 55, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush18);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush19(QColor(26, 49, 55, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        afficher->setPalette(palette4);
        afficher->setFont(font1);
        afficher->setStyleSheet(QString::fromUtf8("#afficher {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#afficher:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        rech = new QPushButton(groupBox_4);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(750, 20, 111, 41));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush20(QColor(26, 49, 55, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush20);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush21(QColor(26, 49, 55, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush21);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush22(QColor(26, 49, 55, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush22);
#endif
        rech->setPalette(palette5);
        rech->setFont(font1);
        rech->setStyleSheet(QString::fromUtf8("#rech {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#rech:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        supprimer = new QPushButton(groupBox_4);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(870, 20, 121, 41));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush23(QColor(26, 49, 55, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush23);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush24(QColor(26, 49, 55, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush24);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush25(QColor(26, 49, 55, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush25);
#endif
        supprimer->setPalette(palette6);
        supprimer->setFont(font1);
        supprimer->setStyleSheet(QString::fromUtf8("#supprimer {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#supprimer:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        nom_projet = new QLineEdit(groupBox_4);
        nom_projet->setObjectName("nom_projet");
        nom_projet->setGeometry(QRect(70, 160, 321, 41));
        nom_projet->setStyleSheet(QString::fromUtf8("#nom_projet{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        nom_projet->setMaxLength(8);
        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(70, 220, 321, 111));
        plainTextEdit->setStyleSheet(QString::fromUtf8("#plainTextEdit{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        id_2 = new QLineEdit(groupBox_4);
        id_2->setObjectName("id_2");
        id_2->setGeometry(QRect(70, 430, 131, 41));
        id_2->setStyleSheet(QString::fromUtf8("#id_2{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        id_2->setMaxLength(8);
        idrep = new QLineEdit(groupBox_4);
        idrep->setObjectName("idrep");
        idrep->setGeometry(QRect(70, 350, 321, 51));
        idrep->setStyleSheet(QString::fromUtf8("#idrep{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        idrep->setMaxLength(8);
        statut = new QComboBox(groupBox_4);
        statut->setObjectName("statut");
        statut->setGeometry(QRect(210, 430, 171, 41));
        statut->setStyleSheet(QString::fromUtf8("#statut{\n"
"\n"
"   background-color: #d7e399\n"
";\n"
"    border: none;\n"
"    border-bottom: 2px solid #1d9000\n"
"\n"
";\n"
"    padding-bottom: 7px;\n"
"    selection-background-color: #1a3137;\n"
"border-radius: 10px;\n"
"}"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 0, 51, 761));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush26(QColor(50, 54, 63, 255));
        brush26.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush26);
        QBrush brush27(QColor(127, 213, 255, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush27);
        QBrush brush28(QColor(63, 191, 255, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush28);
        QBrush brush29(QColor(0, 85, 127, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush29);
        QBrush brush30(QColor(0, 113, 170, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush26);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush26);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush31(QColor(127, 212, 255, 255));
        brush31.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush31);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush27);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush28);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush29);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush26);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush31);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush27);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush28);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush30);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush29);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush26);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush32(QColor(0, 170, 255, 255));
        brush32.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush32);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        groupBox_5->setPalette(palette7);
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 54, 63);\n"
"border-color: rgb(50, 54, 63);\n"
""));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1080, 30, 31, 20));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/log-out.svg")));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1040, 30, 21, 20));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/user (1).svg")));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 30, 21, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/search.svg")));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(990, 20, 31, 41));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/settings.svg")));
        label = new QLabel(groupBox_4);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 40, 241, 31));
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        t = new QPushButton(groupBox_4);
        t->setObjectName("t");
        t->setGeometry(QRect(550, 70, 141, 41));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush33(QColor(26, 49, 55, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush33);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush34(QColor(26, 49, 55, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush34);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush35(QColor(26, 49, 55, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush35);
#endif
        t->setPalette(palette8);
        t->setFont(font1);
        t->setStyleSheet(QString::fromUtf8("#t {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#t:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        p = new QPushButton(groupBox_4);
        p->setObjectName("p");
        p->setGeometry(QRect(1170, 240, 171, 41));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush36(QColor(26, 49, 55, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush36);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush37(QColor(26, 49, 55, 128));
        brush37.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush37);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush38(QColor(26, 49, 55, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush38);
#endif
        p->setPalette(palette9);
        p->setFont(font1);
        p->setStyleSheet(QString::fromUtf8("#p {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#p:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        statistq = new QPushButton(groupBox_4);
        statistq->setObjectName("statistq");
        statistq->setGeometry(QRect(1170, 190, 171, 41));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush39(QColor(26, 49, 55, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush39);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush40(QColor(26, 49, 55, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush40);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush41(QColor(26, 49, 55, 128));
        brush41.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush41);
#endif
        statistq->setPalette(palette10);
        statistq->setFont(font1);
        statistq->setStyleSheet(QString::fromUtf8("#statistq{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#statistq:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        horizontalLayoutWidget = new QWidget(groupBox_4);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(420, 460, 711, 181));
        stat = new QHBoxLayout(horizontalLayoutWidget);
        stat->setObjectName("stat");
        stat->setContentsMargins(0, 0, 0, 0);
        histo = new QPushButton(groupBox_4);
        histo->setObjectName("histo");
        histo->setGeometry(QRect(1170, 290, 171, 41));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush42(QColor(26, 49, 55, 128));
        brush42.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush42);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush43(QColor(26, 49, 55, 128));
        brush43.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush43);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette11.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush44(QColor(26, 49, 55, 128));
        brush44.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush44);
#endif
        histo->setPalette(palette11);
        histo->setFont(font1);
        histo->setStyleSheet(QString::fromUtf8("#histo{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#histo:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        qrcodeLabel = new QLabel(groupBox_4);
        qrcodeLabel->setObjectName("qrcodeLabel");
        qrcodeLabel->setGeometry(QRect(1180, 10, 141, 111));
        t_2 = new QPushButton(groupBox_4);
        t_2->setObjectName("t_2");
        t_2->setGeometry(QRect(1170, 140, 171, 41));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush45(QColor(26, 49, 55, 128));
        brush45.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush45);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush46(QColor(26, 49, 55, 128));
        brush46.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush46);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette12.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush47(QColor(26, 49, 55, 128));
        brush47.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush47);
#endif
        t_2->setPalette(palette12);
        t_2->setFont(font1);
        t_2->setStyleSheet(QString::fromUtf8("#t_2{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#t_2:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        t_2->setAutoDefault(false);
        sendMail = new QPushButton(groupBox_4);
        sendMail->setObjectName("sendMail");
        sendMail->setGeometry(QRect(1160, 600, 181, 41));
        sendMail->setStyleSheet(QString::fromUtf8("#sendMail{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#sendMail:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        contenu = new QPlainTextEdit(groupBox_4);
        contenu->setObjectName("contenu");
        contenu->setGeometry(QRect(1160, 510, 181, 81));
        contenu->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #f4f5f9; /* Fond du texte, blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure autour de la zone de texte */\n"
"    border-radius: 10px; /* Arrondi les coins */\n"
"    padding: 5px; /* Espace autour du texte */\n"
"    color: #1a3137; /* Texte sombre */\n"
"}\n"
"\n"
"QPlainTextEdit:focus {\n"
"    border: 2px solid #92d718; /* Bordure verte lorsque la zone de texte est focus */\n"
"}\n"
"\n"
"QPlainTextEdit::cursor {\n"
"    color: #1a3137; /* Couleur du curseur */\n"
"}\n"
"\n"
"QPlainTextEdit::selection {\n"
"    background-color: #d7e399; /* Fond de la s\303\251lection de texte, jaune p\303\242le */\n"
"    color: #1a3137; /* Texte sombre pour la s\303\251lection */\n"
"}\n"
""));
        dest = new QPlainTextEdit(groupBox_4);
        dest->setObjectName("dest");
        dest->setGeometry(QRect(1160, 450, 181, 41));
        dest->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #f4f5f9; /* Fond du texte, blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure autour de la zone de texte */\n"
"    border-radius: 10px; /* Arrondi les coins */\n"
"    padding: 5px; /* Espace autour du texte */\n"
"    color: #1a3137; /* Texte sombre */\n"
"}\n"
"\n"
"QPlainTextEdit:focus {\n"
"    border: 2px solid #92d718; /* Bordure verte lorsque la zone de texte est focus */\n"
"}\n"
"\n"
"QPlainTextEdit::cursor {\n"
"    color: #1a3137; /* Couleur du curseur */\n"
"}\n"
"\n"
"QPlainTextEdit::selection {\n"
"    background-color: #d7e399; /* Fond de la s\303\251lection de texte, jaune p\303\242le */\n"
"    color: #1a3137; /* Texte sombre pour la s\303\251lection */\n"
"}\n"
""));
        btnPredire = new QPushButton(groupBox_4);
        btnPredire->setObjectName("btnPredire");
        btnPredire->setGeometry(QRect(460, 400, 171, 41));
        QFont font3;
        font3.setBold(true);
        btnPredire->setFont(font3);
        btnPredire->setStyleSheet(QString::fromUtf8("\n"
"  #btnPredire{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#btnPredire:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        btnPredire->setAutoDefault(false);
        label_prediction = new QLabel(groupBox_4);
        label_prediction->setObjectName("label_prediction");
        label_prediction->setGeometry(QRect(790, 380, 361, 71));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        label_prediction->setFont(font4);
        t_3 = new QPushButton(groupBox_4);
        t_3->setObjectName("t_3");
        t_3->setGeometry(QRect(710, 70, 141, 41));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush48(QColor(26, 49, 55, 128));
        brush48.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush48);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush49(QColor(26, 49, 55, 128));
        brush49.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush49);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette13.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush50(QColor(26, 49, 55, 128));
        brush50.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush50);
#endif
        t_3->setPalette(palette13);
        t_3->setFont(font1);
        t_3->setStyleSheet(QString::fromUtf8("#t_3{\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#t_3:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        t_4 = new QPushButton(groupBox_4);
        t_4->setObjectName("t_4");
        t_4->setGeometry(QRect(870, 70, 141, 41));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        QBrush brush51(QColor(26, 49, 55, 128));
        brush51.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush51);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush8);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Inactive, QPalette::Highlight, brush10);
        QBrush brush52(QColor(26, 49, 55, 128));
        brush52.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush52);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette14.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        QBrush brush53(QColor(26, 49, 55, 128));
        brush53.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush53);
#endif
        t_4->setPalette(palette14);
        t_4->setFont(font1);
        t_4->setStyleSheet(QString::fromUtf8("#t_4 {\n"
"    background-color: #f4f5f9; /* Couleur de fond proche du blanc cass\303\251 */\n"
"    border: 2px solid #1a3137; /* Bordure sombre */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px; /* Espace int\303\251rieur pour un meilleur rendu */\n"
"    color: #1a3137; /* Couleur du texte sombre pour un bon contraste */\n"
"    font-size: 16px; /* Taille de police */\n"
"    transition: background-color 0.3s, color 0.3s; /* Transition douce pour les changements de couleur */\n"
"}\n"
"\n"
"#t_4:hover {\n"
"    background-color: #1d9000; /* Couleur de fond verte fonc\303\251e lors du survol */\n"
"    color: #f4f5f9; /* Couleur du texte en blanc cass\303\251 lors du survol pour un bon contraste */\n"
"    cursor: pointer; /* Change le curseur en main pour indiquer une action */\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1326, 26));
        menuprojet = new QMenu(menubar);
        menuprojet->setObjectName("menuprojet");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuprojet->menuAction());

        retranslateUi(MainWindow);

        t_2->setDefault(false);
        btnPredire->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QString());
        id->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID de projet", nullptr));
        ajout->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        modif->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        recherche->setInputMask(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID de recherche", nullptr));
        afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        rech->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        nom_projet->setText(QString());
        nom_projet->setPlaceholderText(QCoreApplication::translate("MainWindow", "nom de projet", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "description", nullptr));
        id_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID de Client", nullptr));
        idrep->setText(QString());
        idrep->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID de responsable", nullptr));
        groupBox_5->setTitle(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_18->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Gestion des Projets", nullptr));
        t->setText(QCoreApplication::translate("MainWindow", "Trier Par Nom", nullptr));
        p->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        statistq->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        histo->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        qrcodeLabel->setText(QString());
        t_2->setText(QCoreApplication::translate("MainWindow", "Qrcode", nullptr));
        sendMail->setText(QCoreApplication::translate("MainWindow", "Envoyer Email", nullptr));
        contenu->setPlaceholderText(QCoreApplication::translate("MainWindow", "Contenu de mail", nullptr));
        dest->setPlaceholderText(QCoreApplication::translate("MainWindow", "@ destinataire ", nullptr));
        btnPredire->setText(QCoreApplication::translate("MainWindow", "Pr\303\251dire D\303\251pense", nullptr));
        label_prediction->setText(QCoreApplication::translate("MainWindow", "Estimation de d\303\251pense : --", nullptr));
        t_3->setText(QCoreApplication::translate("MainWindow", "Trier Par ID", nullptr));
        t_4->setText(QCoreApplication::translate("MainWindow", "Trier Par Status", nullptr));
        menuprojet->setTitle(QCoreApplication::translate("MainWindow", "projet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
