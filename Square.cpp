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


Square::Square(Piece piece)
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
bool isMyOwn(Color color)
{
    return false;
}

/**
 * @param piece
 * @return void
 */
void put(Piece piece)
{
    return;
}

/**
 * @return void
 */
void remove()
{
    return;
}
