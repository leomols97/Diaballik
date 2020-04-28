/**
 * Project Diaballik
 */


#include "Square.h"

using namespace Diaballik;

//Square::Square() {}

/**
 * Square implementation
 */
Square::Square(Piece piece) :
    piece_(piece)
{
    //this->piece_ = piece;
}

/**
 * @return boolean
 */
bool Square::isFree()
{
    return piece_.getColor() == None;
}

/**
 * @param color
 * @return boolean
 */
bool Square::isMyOwn(Color color)
{
    return this->getPiece().getColor() == color;
}

/**
 * @param piece
 * @return void
 */
void Square::put(Piece piece)
{
    if(isFree())
    {
        this->piece_ = piece;
    }
}

/**
 * @return void
 */
void Square::remove()
{
    this->piece_.setColor(None);
}
