#-------------------------------------------------
#
# Project created by QtCreator 2016-08-23T17:16:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    gswidget.cpp \
    gswidgetmax.cpp

HEADERS  += mainwindow.h \
    widget.h \
    gswidget.h \
    gswidgetmax.h

FORMS    += mainwindow.ui \
    gswidget.ui \
    gswidgetmax.ui

DISTFILES += \
    tab1_1.png \
    tab1_2.png \
    tab2_1.png \
    tab2_2.png \
    camera_2.png

RESOURCES += \
    resourcefile.qrc
