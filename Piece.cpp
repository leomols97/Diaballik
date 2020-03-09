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

Color getColor()
{
    return this
}

bool getHasBall()
{
    return
}

void Diaballik::setColor(Color color)
{
    color = color;
}
