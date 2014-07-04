#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T19:23:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = APG-GUI
TEMPLATE = app


SOURCES += main.cpp\
        apgmain.cpp \
    errorvaldialog.cpp \
    scores.cpp \
    errornoapg.cpp

HEADERS  += apgmain.h \
    errorvaldialog.h \
    scores.h \
    errornoapg.h

FORMS    += apgmain.ui \
    errorvaldialog.ui \
    scores.ui \
    errornoapg.ui

CONFIG += c++11
