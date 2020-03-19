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

Piece::Piece()
{
    this->real = false;
}

/**
 * @param color
 */
Piece::Piece(Color color)
{

    this->color = &color;
    this->real = true;
    this->hasBall = false;
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

void Piece::setColor(Color *color)
{
    this->color = color;
}

bool changeHasBall(Piece *piece)
{
    if (piece->getHasBall() ==  true)
    {
        return false;
    }
    else
    {
        return true;
    }
}
