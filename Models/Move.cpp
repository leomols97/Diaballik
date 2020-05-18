/**
 * Project Diaballik
 */


#include "Move.h"

using namespace Diaballik;


/**
 * Move implementation
 */

//Move::Move(){}
/**
 * @param piece
 * @param start
 * @param end
 */
Move::Move(Piece &piece, Position &start, Position &end) :
    piece_(piece),
    start_(start),
    end_(end)
{}
