/**
 * Project Diaballik
 */


#include "Piece.h"
#import "Color.h"
#include <iostream>

using namespace std;
using namespace PieceSpace;

/**
 * Piece implementation
 */


/**
 * @param color
 */
Piece::Piece(Color color, bool hasBall, bool real) {
    this->color = color;
    real = isReal();
    hasBall = false;

}

/**
 * @brief Piece::isReal
 * @param color
 * @return
 */
bool Piece::isReal()
{
    if (color == Black || color == White)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @return boolean
 */
bool Piece::canPassBall() {
    return false;
}

/**
 * @return void
 */
void Piece::passBall() {
    return;
}
