#-------------------------------------------------
#
# Project created by QtCreator 2018-07-19T13:48:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    App/startcommand/startcommand.cpp \
    App/app.cpp \
    Model/model.cpp \
    View/ViewSinks/directionsink.cpp \
    View/ViewSinks/viewprosinks.cpp \
    View/ViewSinks/viewsetsink.cpp \
    View/start.cpp \
    View/view.cpp \
    Viewmodel/Command/directioncommand.cpp \
    Viewmodel/Command/layoutcommand.cpp \
    Viewmodel/ViewmodelSinks/viewmodelsink.cpp \
    Viewmodel/viewmodel.cpp \
    main.cpp

HEADERS += \
    App/startcommand/startcommand.h \
    App/app.h \
    Common/etlbase.h \
    Common/square.h \
    Model/model.h \
    View/ViewSinks/directionsink.h \
    View/ViewSinks/viewprosinks.h \
    View/ViewSinks/viewsetsink.h \
    View/start.h \
    View/view.h \
    Viewmodel/Command/directioncommand.h \
    Viewmodel/Command/layoutcommand.h \
    Viewmodel/ViewmodelSinks/viewmodelsink.h \
    Viewmodel/viewmodel.h

FORMS += \
    View/start.ui \
    View/view.ui

RESOURCES += \
    images.qrc
