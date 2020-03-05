/**
 * Project Diaballik
 */


#include "Square.h"
#include <iostream>

using namespace std;
using namespace SquareSpace;
using namespace PieceSpace;
using namespace ColorSpace;

/**
 * Square implementation
 */


Square::Square(Piece piece)
{
    this->piece = piece;
}

/**
 * @return boolean
 */
bool Square::isFree() {
    return false;
}

/**
 * @param color
 * @return boolean
 */
bool Square::isMyOwn(Color color)
{
    return false;
}

/**
 * @param piece
 * @return void
 */
void Square::put(Piece piece) {
    return;
}

/**
 * @return void
 */
void Square::remove() {
    return;
}
