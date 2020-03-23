TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

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
