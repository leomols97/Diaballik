/**
 * Project Diaballik
 */


#include "Piece.h"
#include "Color.h"
#include <iostream>

using namespace std;
using namespace PieceSpace;
using namespace ColorSpace;

/**
 * Piece implementation
 */

/**
 * @param color
 */
Piece::Piece(Color color)
{
    this->color = color;
    real = true;
    hasBall = false;
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

Color getColor()
{
    return this
}

bool getHasBall()
{
    return
}
