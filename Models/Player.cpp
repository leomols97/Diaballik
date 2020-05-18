/**
 * Project Diaballik
 * Player implementation
 */


#include "Player.h"

using namespace Diaballik;


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
        cout << getPieces().at(i).getColor() << endl;
        Piece p(color);
        pieces_.push_back(p);
    }
}

void Player::addPieceToPlayer(Piece &piece)
{
    pieces_.push_back(piece);
}

/**
 * @brief Piece::isReal
 * @param color
 * @return
 */
bool Player::isReal(Color &color_)
{
    if (color_ == Black || color_ == White || color_ == BlackWithBall || color_ == WhiteWithBall)
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
    for (unsigned int i = 0; i < 8; i++)
    {
        dirs.push_back(Direction());
    }
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
