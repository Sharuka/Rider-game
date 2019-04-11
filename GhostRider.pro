#-------------------------------------------------
#
# Project created by QtCreator 2018-12-25T22:26:21
#
#-------------------------------------------------

QT       += core gui\
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ghostdriver
TEMPLATE = app


SOURCES +=\
    game.cpp \
    health.cpp \
    rider.cpp \
    score.cpp \
    police.cpp \
    main.cpp \
    gameover.cpp \
    button.cpp

HEADERS  += \
    game.h \
    health.h \
    rider.h \
    police.h \
    score.h \
    gameover.h \
    button.h

FORMS    +=

RESOURCES += \
    res.qrc
