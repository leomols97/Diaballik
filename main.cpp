#include <iostream>
#include "Models/Game.h"
#include "View/View.h"
#include "Controller/Controller.h"


using namespace Diaballik;


int main()
{
    Game game;
    View view(game);
    Controller controller(game, view);
    controller.startGame();
    return 0;
}
