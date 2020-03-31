#include <iostream>
#include "Game.h"
#include "View.h"
#include "Controller.h"

using namespace std;
using namespace Diaballik;

int main()
{
    Game game;
    View view;
    Controller controller(game, view);
    controller.startGame();
    return 0;
}
