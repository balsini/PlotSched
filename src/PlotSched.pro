#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T16:49:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlotSched
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        schedulingvisualizer.cpp

HEADERS  += mainwindow.h\
        schedulingvisualizer.hpp

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
