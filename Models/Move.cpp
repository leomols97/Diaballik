/**
 * Project Diaballik
 */


#include "Move.h"

using namespace Diaballik;


Move::Move(Piece &piece, Position &start, Position &end) :
    piece_(piece),
    start_(start),
    end_(end)
{}
