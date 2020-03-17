/**
 * Project Diaballik
 */

#include "Piece.h"
#include "Color.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Piece implementation
 */

Piece::Piece(){}

/**
 * @param color
 */
Piece::Piece(Color *color)
{
<<<<<<< HEAD
    p.colorptr = color;
    p.real = true;
    p.hasBall = false;
=======
    this->color = *color;
    this->real = true;
    this->hasBall = false;
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877
}

/**
 * @return boolean
 */
bool canPassBall() {
    return false;
}

/**
 * @return void
 */

void passBall()
{
    return BLABLA;
}

bool getHasBall()
{
    return true;
}

void Piece::setColor(Color color)
{
<<<<<<< HEAD
    p.color = color;
=======
    this->color = color;
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877
}
