#QT -= gui

#TEMPLATE = app
#CONFIG += console
#CONFIG -= app_bundle
#CONFIG -= qt
#QMAKE_CXXFLAGS += -pedantic-errors\
#-std=c++17

HEADERS += \
    Controller/Controller.h \
    Controller/eventpassball.h \
    Models/Board.h \
    Models/Color.h \
    Models/Direction.h \
    Models/Game.h \
    Models/Move.h \
    Models/Piece.h \
    Models/Plateau.h \
    Models/Player.h \
    Models/Position.h \
    Observer/Observer.h \
    Observer/Subject.h \
    View/View.h \
    menup.h \

SOURCES += \
    Controller/Controller.cpp \
    Controller/eventpassball.cpp \
    Models/Board.cpp \
    Models/Game.cpp \
    Models/Move.cpp \
    Models/Piece.cpp \
    Models/Player.cpp \
    Models/Position.cpp \
    View/View.cpp \
    Observer/Subject.cpp \
    Models/Plateau.cpp \
    mainFX.cpp \
    menup.cpp \


QT += widgets
