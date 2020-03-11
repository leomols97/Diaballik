/**
 * Project Diaballik
 */


#include "Player.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Player implementation
 */

/**
 * Default constructor needed by the constructor of Game
 * @brief Player
 */
Player::Player() {}

/**
 * @param color
 */
Player::Player(Color color) {
    this->color = color;
    this->nbMoves = 2;
    vector<Piece> pieces{7};
    for (unsigned i = 0; i < sizeof(pieces); i++)
    {
        Piece p(color);
        pieces.push_back(p);
    }
}

/**
 * @brief Piece::isReal
 * @param color
 * @return
 */
bool isReal(Color color)
{
    if (color == Black || color == White)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @return boolean
 */
bool canPass() {
    return false;
}

/**
 * @return int
 */
int getNbMoves() {
    return 0;
}

/**
 * @param nbMoves
 * @return void
 */
void setNbMoves(int nbMoves) {
    Diaballik::Player().nbMoves;
}
