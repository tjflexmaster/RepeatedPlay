#-------------------------------------------------
#
# Project created by QtCreator 2012-10-05T09:07:26
#
#-------------------------------------------------

QT       += core gui

TARGET = RepeatedPlay
TEMPLATE = app


SOURCES += main.cpp\
        RepeatedPlay.cpp \
    StrategyInterface.cpp \
    Game.cpp \
    PrisonerDilema.cpp \
    PlayHist.cpp \
    Arena.cpp \
    AlwaysDefect.cpp \
    NeverForgive.cpp \
    TitForTat.cpp \
    TitForTwoTat.cpp \
    AlwaysCooperate.cpp \
    RandomStrategy.cpp \
    Pavlov.cpp \
    WSLS.cpp \
    NeverForgiveUnprovoked.cpp \
    BarGraphWidget.cpp \
    Cheater.cpp

HEADERS  += RepeatedPlay.h \
    StrategyInterface.h \
    Game.h \
    PrisonerDilema.h \
    PlayHist.h \
    Arena.h \
    AlwaysDefect.h \
    NeverForgive.h \
    TitForTat.h \
    TitForTwoTat.h \
    AlwaysCooperate.h \
    RandomStrategy.h \
    Pavlov.h \
    WSLS.h \
    NeverForgiveUnprovoked.h \
    BarGraphWidget.h \
    Cheater.h

FORMS    += repeatedplay.ui
