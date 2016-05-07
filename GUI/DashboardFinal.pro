#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T14:15:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DashboardFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addexpense.cpp \
    addincome.cpp \
    dashboard.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    addexpense.h \
    addincome.h \
    dashboard.h \
    qcustomplot.h

FORMS    += mainwindow.ui
