#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Models/Game.h"
#include "View/View.h"
#include <iostream>
#include <stdexcept>
#include "sstream"
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include "Observer/Observer.h"


using namespace std;
using namespace Diaballik;


namespace Diaballik
{

    class Controller
    {

        /**
         * @brief game_ a new game to start
         */
        Game game_;

        /**
         * @brief view_ all the text we will display on the terminal
         */
        View view_;

        public:

            /**
             * @brief Controller constructs a controller characterised by a game an a view
             * @param game_ a new game to start
             * @param view_ all the text we will display on the terminal
             */
            Controller(Game &game, View &view);

            //~Controller();

            /**
             * @brief initialize initializes all that is necessary to launch a game
             * @param typeOfGame to define which type of game the user would like to play
             */
            //void initialize(int typeOfGame);

            /**
             * @brief startGame launches the game
             */
            void startGame();
    };
}

#endif // CONTROLLER_H
