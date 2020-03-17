/**
 * Project Diaballik
 */


#include "Square.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Square implementation
 */

//Square::Square(){}

Square::Square(Piece *piece)
{
    this->piece = piece;
}

/**
 * @return boolean
 */
bool isFree() {
    return false;
}

/**
 * @param color
 * @return boolean
 */
bool Square::isMyOwn(Color color)
{
    return this->getPiece()->getColor() == color;
}

/**
 * @param piece
 * @return void
 */
void Square::put(Piece *piece)
{
    if(isFree()){
        this->piece = piece;
    }
    //this->piece = &piece;
}

/**
 * @return void
 */
void Square::remove()
{
    this->piece = nullptr;
}
