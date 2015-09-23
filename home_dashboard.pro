#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T22:18:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = home_dashboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp

HEADERS  += mainwindow.h \
    relay.h \
    controller.h

FORMS    += mainwindow.ui
