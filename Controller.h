#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include "View.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Controller
    {


        Game game_;
        View view_;

        public:
            Controller();

            Controller(Game game_, View view_);

            void initialize();

            void startGame();
    };
}

#endif // CONTROLLER_H
