 #include <iostream>
#include "Model/Game.h"
#include "View/View.h"
#include "Controller/Controller.h"

using namespace std;
using namespace Diaballik;

int main()
{
    Game game;
    View view;
    Controller controller(game, view);
    //controller.initialize();
    controller.startGame();
    cout << "simon" << endl;
    return 0;
}
