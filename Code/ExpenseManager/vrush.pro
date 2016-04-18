#-------------------------------------------------
#
# Project created by QtCreator 2016-04-18T17:21:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp
        dashboardGUI.cpp \
        transactionGUI.cpp
        graphGUI.cpp

HEADERS  += mainwindow.h
        dashboardGUI.h \
        trsansactionGUI.h
        graphGUI.h
        enumGUI.h

FORMS    += mainwindow.ui
