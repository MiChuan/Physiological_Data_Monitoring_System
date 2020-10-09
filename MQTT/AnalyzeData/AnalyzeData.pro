#-------------------------------------------------
#
# Project created by QtCreator 2020-10-04T21:30:16
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT+= charts
QT+= network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnalyzeData
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pages/welcome.cpp \
    tools/dbhelper.cpp \
    pages/login.cpp \
    pages/draw.cpp \
    pages/analyze.cpp \
    pages/chart.cpp \
    pages/chartview.cpp \
    pages/timeeditdelegate.cpp \
    tools/zsmtp.cpp

HEADERS += \
        mainwindow.h \
    pages/welcome.h \
    pages/pages.h \
    tools/dbhelper.h \
    pages/login.h \
    pages/draw.h \
    pages/analyze.h \
    pages/chart.h \
    pages/chartview.h \
    pages/timeeditdelegate.h \
    tools/zsmtp.h

FORMS += \
        mainwindow.ui \
    pages/welcome.ui \
    pages/login.ui \
    pages/draw.ui \
    pages/analyze.ui

RESOURCES += \
    pic.qrc
