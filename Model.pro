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
    Model/Board.h \
    Model/Color.h \
    Model/Direction.h \
    Model/Game.h \
    Model/Model.h \
    Model/Move.h \
    Model/Piece.h \
    Model/Player.h \
    Model/Position.h \
    Model/Square.h \
#    Move.h \
#    Observable.h \
#    Observer.h \
    Observer/Observable.h \
    Observer/Observer.h \
#    Piece.h \
#    Player.h \
#    Position.h \
#    Square.h \
#    View.h \
    View/View.h

SOURCES += \
#        Board.cpp \
#        Controller.cpp \
        Controller/Controller.cpp \
#        Direction.cpp \
#        Game.cpp \
        Model/Board.cpp \
        Model/Direction.cpp \
        Model/Game.cpp \
        Model/Move.cpp \
        Model/Piece.cpp \
        Model/Player.cpp \
        Model/Position.cpp \
        Model/Square.cpp \
#        Move.cpp \
#        Piece.cpp \
#        Player.cpp \
#        Position.cpp \
#        Square.cpp \
#        View.cpp \
        View/View.cpp \
        main.cpp
