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

        protected:



        public:

            Board board;
            Player current;
            Player opponent;
            Position selected;

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


    void initialize();

    /**
* @param player
*/
    bool foulGame(Player player );

    bool isOver();

    /**
* @param row
* @param column
*/
    void select(int row , int column);

    void swapPlayers();

    void start();

    /**
* @param selected
*/
    vector<Move> getMoves(Position selected );

    /**
* @param move
*/
    void apply(Move move );

    /**
* @param player
*/
    bool hasMoves(Player player);

    Player getWinner();
}
#endif //_GAME_H
