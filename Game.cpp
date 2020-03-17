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
void Game::select(int row , int column)
{
    //exceptions à rajouter
    this->selected = Position(row, column);
}

/**
 * @return void
 */
void Game::swapPlayers()
{
    if (!hasMoves(current)/*autre condition à rajouter s'il décide de ne pas utiliser tous ses mouvements*/) {
        Player provisoire = current;
        current = opponent;
        opponent = provisoire;
    }
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
void Game::apply(Move move)
{
    // créer 2 méthodes getPiece(move) (une qui retourne un pointeur de piece et l'autre une piece)
    Piece piece = board.getPiece(move.getStart());
    if (board.isFree(move.getEnd())) {
        board.remove(move.getStart());
        board.put(piece, move.getEnd());
    }

}
/**
 * @param player
 * @return boolean
 */
bool hasMoves(Player player)
{

    return player.getNbMoves() > 0;
    //return BLABLA;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    //rajouter condition de anti-jeu
    return this->current;
}
