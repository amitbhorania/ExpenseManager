#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T14:28:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpenseManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    date.cpp \
    transaction.cpp

HEADERS  += mainwindow.h \
    date.h \
    transaction.h \
    enums.h

FORMS    += mainwindow.ui
