QT += core
QT -= gui

CONFIG += c++11

TARGET = Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    date.cpp \
    menu.cpp \
    transaction.cpp \
    writeDB.cpp

HEADERS += \
    date.h \
    enums.h \
    menu.h \
    transaction.h \
    writeDB.h
