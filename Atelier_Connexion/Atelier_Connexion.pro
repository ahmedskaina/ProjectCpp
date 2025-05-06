#-------------------------------------------------
#
# Project migrated to Qt 6
#
#-------------------------------------------------

QT += core gui widgets sql serialport multimedia printsupport
QT += charts  # Nécessite le module Qt Charts installé séparément

CONFIG += c++17  # Qt 6 requiert C++17 minimum

# Dépréciations
DEFINES += QT_DEPRECATED_WARNINGS
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Fichiers UI
FORMS += \
    dialog_stats.ui \
    loginn.ui \
    recorder.ui \
    mainwindow.ui

TARGET = Atelier_Connexion
TEMPLATE = app

# Sources
SOURCES += \
    dialog_stats.cpp \
    employe.cpp \
    loginn.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    qrcodeg.cpp

# Headers
HEADERS += \
    dialog_stats.h \
    employe.h \
    loginn.h \
    mainwindow.h \
    connection.h \
    qrcodeg.h

# Ressources (ajouter si nécessaire)
# RESOURCES += resources.qrc

# Déploiement
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
