#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T20:38:34
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = db
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    DBProcess.cpp

HEADERS  += widget.h \
    DBProcess.h

FORMS    += widget.ui
