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
using namespace BoardSpace;
using namespace PlayerSpace;
using namespace MoveSpace;
using namespace PositionSpace;

namespace GameSpace {


    class Game: public Model {

        private:

            Board board;
            Player current;
            Player opponent;
            Position selected;

        public:

            Game();

            // ATTENTION IL NE FAUT PAS OUBLIER LES DESTRUCTEURS !!!!!!!!!

            inline Board getBoard() const
            {
                return board;
            }

            inline Position getSelected() const
            {
                return selected;
            }

            inline Player getCurrent() const
            {
                return current;
            }

            inline Player getOpponent() const
            {
                return opponent;
            }

    };

    static void initialize();

    /**
* @param player
*/
    static bool foulGame(Player player );

    static bool isOver();

    /**
* @param row
* @param column
*/
    static void select(int row , int column);

    static void swapPlayers();

    static void start();

    /**
* @param selected
*/
    static vector<Move> getMoves(Position selected );

    /**
* @param move
*/
    static void apply(Move move );

    /**
* @param player
*/
    static bool hasMoves(Player player);

    static Player getWinner();
}
#endif //_GAME_H
