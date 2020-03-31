TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -pedantic-errors\
-std=c++17

HEADERS += \
    Board.h \
    Color.h \
    Controller.h \
    Direction.h \
    Game.h \
    Model.h \
    Move.h \
    Observable.h \
    Observer.h \
    Piece.h \
    Player.h \
    Position.h \
    Square.h \
    View.h

SOURCES += \
        Board.cpp \
        Controller.cpp \
        Direction.cpp \
        Game.cpp \
        Move.cpp \
        Piece.cpp \
        Player.cpp \
        Position.cpp \
        Square.cpp \
        View.cpp \
        main.cpp
