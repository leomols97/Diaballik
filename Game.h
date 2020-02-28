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

namespace GameSpace {


    class Game: public Model {

    private:
        Board board;
        Player current;
        Player opponent;
        Position selected;

    public:

    Game();

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

    Board getBoard();

    Position getSelected();

    Player getCurrent();

    Player getOpponent();

    };
}
#endif //_GAME_H
