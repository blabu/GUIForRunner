#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T10:41:07
#
#-------------------------------------------------

QT += core gui
QT += network
QT += widgets

TARGET = untitled
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        widget.cpp \
    TcpLayer.cpp \
    ConnectionInterface.cpp

HEADERS  += widget.h \
    TcpLayerr.h \
    ConnectionInterface.h

FORMS    += widget.ui
