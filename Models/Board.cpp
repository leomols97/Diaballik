﻿
/**
 * Project Diaballik
 */


#include "Board.h"
#include "Piece.h"

using namespace Diaballik;


/**
 * Default constructor needed by the constructor of Game
 * @brief Board::Board
 */

Board::Board(unsigned int boardLength) :
    board_(boardLength),
    boardLength_(boardLength)
{
    vector<vector<Piece>> board;
    for (unsigned int i = 1; i <= boardLength_; i++)
    {
        //board[i].reserve(7);
        vector<Piece> lign;
        for (unsigned int j = 1; j <= boardLength_; j++)
        {
            Piece p(None);
            lign.push_back(p);
        }
        board.push_back(lign);
    }
    board_ = board;
}

/*Board::~Board()
{
    for (unsigned int i = 0; i < board_.size(); i++) {
        for (unsigned int j {0}; j < board_.size(); j++) {
            //remove(Position(i, j));
            delete &getBoard()[i][j];
        }
    }
}*/

/**
 * @param position
 * @return boolean
 */

bool Board::isInside(Position position) const
{
    return position.getRow() > -1
            && position.getRow() < boardLength_
            && position.getColumn() > -1
            && position.getColumn() < boardLength_;
}

/**
 * @param position
 * @return Piece
 */
Piece Board::getPiece(Position position) const
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return this->board_[position.getRow()][position.getColumn()];
}

/**
 * @param position
 * @return boolean
 */
bool Board::isFree(Position position) const
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return getPiece(position).getColor() == None;
}

bool Board::isEmpty()
{
    bool empty = false;
    for (unsigned int i = 0; i < board_.size(); i++)
    {
        for (unsigned int j = 0; j < board_[i].size(); j++)
        {
            Position pos(i, j);
            if(!isFree(pos))
            {
                empty = false;
            }
            else
            {
                empty = true;
            }
        }
    }
    return empty;
}

/**
 * @param piece
 * @param position
 * @return void
 */
void Board::put(Player player, Position position)
{
    this->board_[position.getRow()][position.getColumn()].setColor(player.getColor());
}

bool Board::isMyOwn(Position position, Color color) const
{
    return getPiece(position).getColor() == color;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> Board::getTakenSquares(Player player)
{
    Position pos(0,0);
    vector<Position> positions;
    for (unsigned int i = 0; i < getBoard().size(); i++)
    {
        for (unsigned int j = 0; j < getBoard()[i].size(); j++)
        {
            pos.setRow(i);
            pos.setColumn(j);
            if (isMyOwn(pos, player.getColor()))
            {
                positions.push_back(pos);
            }
            pos.setRow(0);
            pos.setColumn(0);
        }
    }
    return positions;
}

/*Square Board::getSquare(Position position) const
{
    return this->board_[position.getRow()][position.getColumn()];
}*/

/**
 * @return vector<vector<Square>>
 */



/**
 * @param position
 * @return void
 */
void Board::remove(Position position)
{
    this->board_[position.getRow()][position.getColumn()].setColor(None);
}
