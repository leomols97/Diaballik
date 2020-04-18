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
             * @brief Controller constructs an empty controller
             */
            Controller();

            /**
             * @brief Controller constructs a controller characterised by a game an a view
             * @param game_ a new game to start
             * @param view_ all the text we will display on the terminal
             */
            Controller(Game game_, View view_);

            /**
             * @brief initialize initializes all that is necessary to launch a game
             */
            void initialize();

            /**
             * @brief startGame launches the game
             */
            void startGame();
    };
}

#endif // CONTROLLER_H
