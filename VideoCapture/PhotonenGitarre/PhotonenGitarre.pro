#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T13:15:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PhotonenGitarre
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hsvprocessor.cpp

HEADERS  += mainwindow.h \
    hsvprocessor.h

FORMS    += mainwindow.ui

include(../opencv/videoengine.pri)
