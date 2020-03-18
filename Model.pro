TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Board.cpp \
        Direction.cpp \
        Game.cpp \
        Move.cpp \
        Piece.cpp \
        Player.cpp \
        Position.cpp \
        Square.cpp \
        View.cpp

HEADERS += \
    Board.h \
    Color.h \
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
