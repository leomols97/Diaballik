
/**
 * Project Diaballik
 */


#include "Board.h"
#include "Position.h"
#include "Piece.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Board implementation
 */

/**
 * Default constructor needed by the constructor of Game
 * @brief Board::Board
 */
Board::Board() {}

Board::Board(vector<vector<Square>> board)
{
    board.reserve(7);
    Position pos(0,0);
    for (unsigned i = 0; i < board.size(); i++)
    {
        board[i].reserve(7);
        vector<Square> lign;
        for (unsigned j = 0; j < board[i].size(); j++)
        {
            Piece p;
            Square sq(p);
            lign.push_back(sq);
        }
        board.push_back(lign);
    }
}

/**
 * @param position
 * @return boolean
 */

bool Board::isInside(Position position)
{
    return position.getRow() > 0
            && position.getRow() < 6
            && position.getColumn() > 0
            && position.getColumn() < 6;
}

/**
 * @param position
 * @return Piece
 */
Piece Board::getPiece(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return getSquare(position).getPiece();
}

/**
 * @param position
 * @return boolean
 */
bool Board::isFree(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return getPiece(position).isReal();
}

bool Board::isEmpty(){
    for (unsigned i = 0; i < board_.size(); i++)
    {
        for (unsigned j = 0; j < sizeof (board_[i].size()); j++)
        {
            Position pos(i, j);
            if(!isFree(pos))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

/**
 * @param piece
 * @param position
 * @return void
 */
void Board::put(Piece piece, Position position)
{
    getSquare(position).put(piece);
}

bool Board::isMyOwn(Position position, Color color)
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
    for (unsigned i = 0; i < sizeof(getBoard()); i++)
    {
        for (unsigned j = 0; j < sizeof (getBoard()[i]); j++)
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

Square Board::getSquare(Position position)
{
    return this->board_[position.getRow()][position.getColumn()];
}

/**
 * @return vector<vector<Square>>
 */
vector<vector<Square>> Board::getBoard()
{
    return this->board_;
}


/**
 * @param position
 * @return void
 */
void Board::remove(Position position)
{
    getSquare(position).remove();
}

void Board::initialize()
{
    //board.reserve(7);
    for (unsigned i = 0; i < board_.size(); i++)
    {
        //board[i].reserve(7);
        for (unsigned j = 0; j < sizeof (board_[i].size()); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(Black);
                Piece().changeHasBall(&p);
                board_[i][j].put(p);
            }
            else if (i == 6 && j == 3)
            {
                Piece p(White);
                Piece().changeHasBall(&p);
                board_[i][j].put(p);
            }
            else if (i == 0)
            {
                Piece p(Black);
                board_[i][j].put(p);
            }
            else if (i == 6)
            {
                Piece p(White);
                board_[i][j].put(p);
            }
            else
            {
                Piece p;
                board_[i][j].put(p);
            }
        }
    }
}
