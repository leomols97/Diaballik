HEADERS += \
#    Board.h \
#    Color.h \
#    Controller.h \
    Controller/Controller.h \
#    Direction.h \
#    Game.h \
#    Model.h \
    Controller/eventpassball.h \
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
    Observer/Observer.h \
#    Piece.h \
#    Player.h \
#    Position.h \
#    View.h \
    Observer/Subject.h \
    View/View.h \
    plateau.h \
    menup.h \

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
        View/View.cpp \
        Observer/Subject.cpp \
        main.cpp \
        plateau.cpp \
        menup.cpp \


QT += widgets
