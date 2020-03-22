/**
 * Project Diaballik
 */


#include "Player.h"
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
    this->color = &color;
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

vector<Direction> allDirections ()
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

/**
 * @return int
 */
int getNbMoves(Player player)
{
    int nbMoves = 0;
    Position selected;
    vector<Direction> directions;
    for (unsigned i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned i = 0; i < Board().getBoard().size(); i++)
    {
        for (unsigned i = 0; i < Board().getBoard()[i].size(); i++)
        {
            for (unsigned i = 0; i < 4; i++)
            {
                if (Board().isInside(selected.next(selected, directions.at(i)))
                        && Board().isFree(selected.next(selected, directions.at(i))))
                {
                    nbMoves++;
                }
                if (Board().isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && Board().isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i))))
                {
                    nbMoves++;
                }
            }
        }
    }
    return 2;
}

/**
 * @param nbMoves
 * @return void
 */
void setNbMoves(int nbMoves)
{
    
}
