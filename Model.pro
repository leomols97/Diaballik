QT -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors\
-std=c++17

HEADERS += \
#    Board.h \
#    Color.h \
#    Controller.h \
    Controller/Controller.h \
#    Direction.h \
#    Game.h \
#    Model.h \
    Models/Board.h \
    Models/Color.h \
    Models/Direction.h \
    Models/Game.h \
#    Models/Model.h \
    Models/Move.h \
    Models/Piece.h \
    Models/Player.h \
    Models/Position.h \
#    Move.h \
#    Observable.h \
#    Observer.h \
    Observer/Observable.h \
    Observer/Observer.h \
#    Piece.h \
#    Player.h \
#    Position.h \
#    View.h \
    View/View.h

SOURCES += \
#        Board.cpp \
#        Controller.cpp \
        Controller/Controller.cpp \
#        Direction.cpp \
#        Game.cpp \
        Models/Board.cpp \
        Models/Direction.cpp \
        Models/Game.cpp \
        Models/Move.cpp \
        Models/Piece.cpp \
        Models/Player.cpp \
        Models/Position.cpp \
#        Move.cpp \
#        Piece.cpp \
#        Player.cpp \
#        Position.cpp \
#        View.cpp \
        View/View.cpp \
        Models/main.cpp
