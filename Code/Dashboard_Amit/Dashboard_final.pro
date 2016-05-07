#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T17:19:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Dashboard_final
TEMPLATE = app


SOURCES += main.cpp\
        dashboard.cpp \
    qcustomplot.cpp \
    addexpense.cpp \
    addincome.cpp

HEADERS  += dashboard.h \
    qcustomplot.h \
    addexpense.h \
    addincome.h

DISTFILES += \
    qcustomplot.qch
