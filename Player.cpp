/**
 * Project Diaballik
 */


#include "Player.h"
#include "Piece.h"
#include "Board.h"
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
    this->color_ = color;
    this->nbMoves_ = 2;
    vector<Piece> pieces{7};
    hasPass_=true;
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
bool Player::isReal(Color color)
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

vector<Direction> Player::allDirections ()
{
    vector<Direction> dirs;
    for (unsigned i = 0; i < 4; i++)
    {
         dirs.push_back(Direction());
    }
    /*
     * OU (à la place du for, si le for ne fonctionne pas)
     * dirs.push_back(Direction::UP);
     * dirs.push_back(Direction::DOWN);
     * dirs.push_back(Direction::RIGHT);
     * dirs.push_back(Direction::LEFT);
     */
    return dirs;
}

void Player::setNbMoves(int nbMoves)
{
    this->nbMoves_ = nbMoves;
}

void Player::setColor(Color color)
{
    this->color_ = color;
}
