/**
 * Project Diaballik
 */


#include "Player.h"

using namespace Diaballik;

/**
 * Player implementation
 */

/**
 * Default constructor needed by the constructor of Game
 * @brief Player
 */
/*Player::Player() :
{
    cout << "va te faire foutre" << endl;
}*/

/**
 * @param color
 */
Player::Player(Color color) :
    color_(color),
    pieces_(getPieces()),
    nbMoves_(2),
    hasPass_(true)
{
    for (unsigned int i = 0; i < pieces_.size(); i++)
    {
        Piece p(color);
        pieces_.push_back(p);
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
    for (unsigned int i = 0; i < 4; i++)
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
