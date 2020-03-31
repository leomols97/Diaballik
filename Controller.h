#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Game.h"
#include "View.h"

using namespace std;

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

            int stringToInteger(int index, stringstream com, vector<int> list);

            constexpr int str2int(char* str, int h = 0);
    };
}

#endif // CONTROLLER_H
