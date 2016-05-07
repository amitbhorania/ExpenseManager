QT += core
QT -= gui

CONFIG += c++11

TARGET = Expense_Manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    readdatabase.cpp \
    writedatabase.cpp \
    date.cpp \
    transaction.cpp \
    mainwindow.cpp

HEADERS += \
    readdatabase.h \
    writedatabase.h \
    date.h \
    transaction.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
