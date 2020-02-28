
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




Board::Board() {

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
List<Position> Board::getTakenSquare(Player player) {
    return null;
}

/**
 * @return Square [][]
 */
Square [][] Board::getSquares() {
    return null;
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
Piece Board::getPiece(Position position) {
    return null;
}
