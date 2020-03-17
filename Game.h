/**
 * Project Diaballik
 */


#ifndef _GAME_H
#define _GAME_H

#include "Model.h"
#import "Player.h"
#import "Move.h"
#import "Board.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Game: public Model
    {

        private:

            Board board;
            Player current;
            Player opponent;
            Position selected;


        public:

            Game();

            // ATTENTION IL NE FAUT PAS OUBLIER LES DESTRUCTEURS !!!!!!!!!

            /**
             * @return Board
             */
            inline Board getBoard() const
            {
                return board;
            }

            /**
             * @brief getSelected
             * @return
             */
            inline Position getSelected() const
            {
                return selected;
            }

            /**
             * @brief getCurrent
             * @return
             */
            inline Player getCurrent() const
            {
                return current;
            }

            /**
             * @brief getOpponent
             * @return
             */
            inline Player getOpponent() const
            {
                return opponent;
            }

            Player getWinner();

<<<<<<< HEAD
            void select(int row , int column);

            void swapPlayers();
=======
            /**
        * @param row
        * @param column
        */
            void select(int row , int column);

            void swapPlayers();
    };
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877

            void start();

            void initialize();

            /**
        * @param player
        */
            bool foulGame(Player player );

            bool isOver();

<<<<<<< HEAD
            /**
        * @param row
        * @param column
        */

            /**
        * @param selected
        */
            vector<Move> getMoves(Position selected );

            /**
        * @param move
        */
            void apply(Move move );
=======
    void start();
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877

            /**
        * @param player
        */
            bool hasMoves(Player player);
    };



}
#endif //_GAME_H
