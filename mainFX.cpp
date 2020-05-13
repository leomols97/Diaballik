#include <iostream>
#include "Game.h"
#include "View/View.h"
#include "Controller/Controller.h"
#include <QApplication>
#include "menup.h"
#include "Plateau.h"


int mainFX(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MenuP menu;
    menu.show();

    return app.exec();
}

