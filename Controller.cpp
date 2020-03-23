#include "Controller.h"
#include "Game.h"
#include "View.h"
#include "sstream"

using namespace std;
using namespace Controlleur;
using namespace Vue;

Controller::Controller() {}

Controller::Controller(Game game, View view)
{
    this->game = game;
    this->view = view;
}

void initialize()
{
    Game().initialize();
    View().Initialize();
}

void startGame()
{
    initialize();
    Game().start();
    View().displayHelpInit();
    View().displayBoard(Game().getBoard().getBoard());
    while (!Game().isOver())
    {
        BLABLA;
    }
}

int stringToInteger(int index, stringstream com, vector<int> list)
{
    int number;
    try
    {
        string token;
        while(getline(com, token, ' '))
        {
            stringstream(token) << number;
            list.push_back(number);
        }
    }
    catch (const exception e)
    {
        cout << "ce n'est pas un entier";
    }
    return list[index];
}
