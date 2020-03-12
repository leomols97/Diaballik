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
    return BLABLA;
}

/**
 * @return void
 */
void swapPlayers()
{
    return BLABLA;
}

/**
 * @return void
 */
void start()
{
    return BLABLA;
}

/**
 * @param selected
 * @return List<Move>
 */

vector<Move> getMoves(Position selected)
{
    return null;
}

/**
 * @param move
 * @return void
 */
void apply(Move move)
{
    return BLABLA;
}

/**
 * @param player
 * @return boolean
 */
bool hasMoves(Player player)
{
    return BLABLA;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    return this->current;
}

