#include <iostream>
#include "Models/Game.h"
#include "View/View.h"
#include "Controller/Controller.h"
#include <QApplication>
#include "menup.h"
#include "Models/Plateau.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MenuP menu;
    menu.show();

    return app.exec();
}

