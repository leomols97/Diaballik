HEADERS += \
#    Board.h \
#    Color.h \
#    Controller.h \
    Controller/Controller.h \
#    Direction.h \
#    Game.h \
#    Model.h \
    Controller/eventpassball.h \
    Board.h \
    Color.h \
    Direction.h \
    Game.h \
    Move.h \
    Piece.h \
    Plateau.h \
    Player.h \
    Position.h \
#    Move.h \
#    Observable.h \
#    Observer.h \
    Observer/Observer.h \
#    Piece.h \
#    Player.h \
#    Position.h \
#    View.h \
    Observer/Subject.h \
    View/View.h \
    mafenetre.h \
    menup.h \

    mafenetre.h \

SOURCES += \
#        Board.cpp \
#        Controller.cpp \
        Controller/Controller.cpp \
#        Direction.cpp \
#        Game.cpp \
    Controller/eventpassball.cpp \
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
    Models/mafenetre.cpp \
        View/View.cpp \
        Observer/Subject.cpp \
#        Models/main.cpp \
        Models/Plateau.cpp \
        mainFX.cpp \
        menup.cpp \

        Models/mafenetre.cpp \


QT += widgets
