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
Piece::Piece(Color color)
{
    this->color = color;
    real = true;
    hasBall = false;
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
void passBall() {
    return;
}

Color Piece::getColor()
{
    return this->color;
}

bool getHasBall()
{
    return true;
}

void Piece::setColor(Color color)
{
    this->color = color;
}
