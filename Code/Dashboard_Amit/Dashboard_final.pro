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
    addincome.cpp \
    graphdata.cpp \
    date.cpp \
    transaction.cpp \
    readdatabase.cpp \
    writedatabase.cpp

HEADERS  += dashboard.h \
    qcustomplot.h \
    addexpense.h \
    addincome.h \
    graphdata.h \
    date.h \
    enums.h \
    transaction.h \
    readdatabase.h \
    writedatabase.h

DISTFILES += \
    qcustomplot.qch \
    Dashboard_UML.qmodel
