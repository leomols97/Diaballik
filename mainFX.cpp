#include <iostream>
#include "Models/Game.h"
#include "View/View.h"
#include "Controller/Controller.h"
#include <QApplication>
#include "Models/menup.h"
#include "Models/Plateau.h"
#include "Models/mafenetre.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*MaFenetre fenetre;
    fenetre.show();*/

    //Board board(7);
    MenuP menu/*(board)*/;
    menu.show();

    return app.exec();
}

