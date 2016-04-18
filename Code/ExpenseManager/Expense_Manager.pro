QT += core
QT -= gui

CONFIG += c++11

TARGET = Expense_Manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    readdatabase.cpp \
    writedatabase.cpp

HEADERS += \
    readdatabase.h \
    writedatabase.h
