#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T23:25:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ExpenseManager
TEMPLATE = app


SOURCES += main.cpp\
        dashboard.cpp \
    addexpense.cpp \
    addincome.cpp \
    date.cpp \
    graphdata.cpp \
    qcustomplot.cpp \
    readdatabase.cpp \
    transaction.cpp \
    writedatabase.cpp

HEADERS  += dashboard.h \
    addexpense.h \
    addincome.h \
    date.h \
    enums.h \
    graphdata.h \
    qcustomplot.h \
    readdatabase.h \
    transaction.h \
    writedatabase.h
