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
Move::Move(Piece piece, Position start, Position end) {
    this->piece = piece;
    this->end = end;
    this->start = start;
}

