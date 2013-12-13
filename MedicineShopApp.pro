#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T16:03:54
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets
QT   +=core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedicineShopApp
TEMPLATE = app
QT +=webkitwidgets


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    addmed.cpp \
    authdialog.cpp \
    changepass.cpp \
    persons.cpp \
    dialogcalendar.cpp \
    smtp.cpp \
    dialogcalculator.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    addmed.h \
    authdialog.h \
    changepass.h \
    persons.h \
    dialogcalendar.h \
    smtp.h \
    dialogcalculator.h

FORMS    += mainwindow.ui \
    dialog.ui \
    addmed.ui \
    authdialog.ui \
    changepass.ui \
    dialogcalendar.ui \
    dialogcalculator.ui

RESOURCES += \
    icons.qrc
