#include <iostream>
#include "Game.h"
#include "View.h"
#include "Controller.h"

using namespace std;
using namespace Vue;
using namespace Controlleur;

int main()
{
    Game game;
    View view;
    Controller controller(game, view);
    controller.startGame();
    return 0;
}
