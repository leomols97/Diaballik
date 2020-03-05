
/**
 * Project Diaballik
 */


#include "Board.h"
#include "Position.h"
#include "Piece.h"
#include <iostream>

using namespace std;
using namespace SquareSpace;
using namespace BoardSpace;

/**
 * Board implementation
 */

/**
 * Default constructor needed by the constructor of Game
 * @brief Board::Board
 */
Board::Board() {}

Board::Board(vector<vector<Square>> board)
{
    this->board = board;
}

/**
 * @param position
 * @return boolean
 */
bool isInside(Position position)
{
    return position.getRow() < 0
            || position.getRow() > 6
            || position.getColumn() < 0
            || position.getColumn() > 6;
}

/**
 * @param position
 * @return boolean
 */
bool isFree(Position position) {
    return false;
}

/**
 * @param piece
 * @param position
 * @return void
 */
void put(Piece piece, Position position) {
    return;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> getTakenSquare(Player player) {
    return null;
}

/**
 * @return Square [][]
 */
vector<vector<Square>> getBoard() {
    return null;
}


/**
 * @param position
 * @return void
 */
void remove(Position position) {
    return;
}

/**
 * @param position
 * @return Piece
 */
Piece getPiece(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return getBoard()[position.getRow()][position.getColumn()].getPiece();
}
