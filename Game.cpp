/**
 * Project Diaballik
 */


#include "Game.h"
#include "Direction.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Game implementation
 */


Game::Game()
{
    Board board(vector<vector<Square>> board);
    Player current(White), oponent(Black);
    Position selected(int row, int column);
}

/**
 * @return void
 */
void initialize()
{
    Game game;
}

/**
 * @param player
 * @return boolean
 */
bool foulGame(Player player)
{
    return false;
}

/**
 * @return boolean
 */
bool isOver()
{
    return false;
}

/**
 * @param row
 * @param column
 * @return void
 */
void select(int row , int column)
{
    return;
}

/**
 * @return void
 */
void swapPlayers()
{
    return;
}

/**
 * @return void
 */
void start()
{
    return;
}

/**
 * @param selected
 * @return List<Move>
 */

vector<Move> getMoves(Position selected )
{
    return null;
}

/**
 * @param move
 * @return void
 */
void apply(Move move )
{
    return;
}

/**
 * @param player
 * @return boolean
 */
bool hasMoves(Player player)
{
    return false;
}

/**
 * @return Player
 */
Player getWinner()
{
<<<<<<< HEAD
    return this->current;
=======
    return Game().current;
>>>>>>> 464b33679382e25399a8e076f2ccf3baa5df2c5a
}

/**
 * @return Board
 */
Board getBoard()
{
    return Board().board;
}

/**
 * @return Position
 */
Position getSelected()
{
    return null;
}

/**
 * @return Player
 */
Player getCurrent()
{
    return null;
}

/**
 * @return Player
 */
Player getOpponent()
{
    return null;
}
