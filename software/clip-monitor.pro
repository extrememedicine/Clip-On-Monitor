#-------------------------------------------------
#
# Project created by QtCreator 2015-06-10T12:28:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clip-monitor
TEMPLATE = app

QT += serialport

SOURCES += main.cpp\
        widget.cpp \
    graphwidget.cpp

HEADERS  += widget.h \
    graphwidget.h

FORMS    += widget.ui
