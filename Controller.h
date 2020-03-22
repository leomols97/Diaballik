#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include "View.h"

using namespace std;

namespace Controlleur
{

    class Controller
    {


        Game game;
        Vue::View view;

        public:
            Controller();

            Controller(Game game, Vue::View view);

            void initialize();

            void startGame();

            int stringToInteger(int index, stringstream com);
    };
}

#endif // CONTROLLER_H
