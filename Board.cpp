
/**
 * Project Diaballik
 */


#include "Board.h"
#import "Position.h"
#import "Piece.h"
#include <iostream>

using namespace std;
using namespace BoardSpace;

/**
 * Board implementation
 */

Board::Board(vector<vector<Square>> squares)
{

    /*Square square(piece);
    for (unsigned i = 0; i < 7; i++)
    {
        for (i = 0; i < 7; i++)
        {
            squares.push_back(square);
        }
    }*/

    this->squares = squares;
}

/**
 * @param position
 * @return boolean
 */
bool Board::isInside(Position position) {
    return false;
}

/**
 * @param position
 * @return boolean
 */
bool Board::isFree(Position position) {
    return false;
}

/**
 * @param piece
 * @param position
 * @return void
 */
void Board::put(Piece piece, Position position) {
    return;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position>* Board::getTakenSquare(Player player) {
    return nullptr;
}

/**
 * @return Square [][]
 */
vector<vector<Square>>* Board::getSquares() {
    return nullptr;
}


/**
 * @param position
 * @return void
 */
void Board::remove(Position position) {
    return;
}

/**
 * @param position
 * @return Piece
 */
Piece* Board::getPiece(Position position) {
    return nullptr;
}
