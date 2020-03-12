/**
 * Project Diaballik
 */


#include "Move.h"
#import "Position.h"
#import "Piece.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Move implementation
 */


/**
 * @param piece
 * @param start
 * @param end
 */
<<<<<<< HEAD
Move(Piece piece, Position start, Position end)
{

}

/**
 * @return Piece
 */
Piece getPiece()
{
    return null;
}

/**
 * @return position
 */
Position getStart()
{
    return null;
}

/**
 * @return Position
 */
Position getEnd()
{
    return null;
}
=======
Move::Move(Piece piece, Position start, Position end) {
    this->piece = piece;
    this->end = end;
    this->start = start;
}

>>>>>>> 464b33679382e25399a8e076f2ccf3baa5df2c5a
