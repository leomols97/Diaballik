
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
    for (unsigned i = 0; i < 7; i++)
    {
        for (unsigned i = 0; i < 7; i++)
        {
            Square
        }
    }
    this->board = board;
}

/**
 * @param position
 * @return boolean
 */
bool isInside(Position position)
{
    return position.getRow() > 0
            || position.getRow() < 6
            || position.getColumn() > 0
            || position.getColumn() < 6;
}

/**
 * @param position
 * @return boolean
 */
bool isFree(Position position)
{
    return false;
}

/**
 * @param piece
 * @param position
 * @return void
 */
void put(Piece piece, Position position)
{
    return;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> getTakenSquare(Player player)
{
    Position pos(0,0);
    vector<Position> positions;
    for (unsigned i = 0; i < sizeof(getBoard()); i++)
    {
        for (unsigned j = 0; j < sizeof (getBoard()); j++)
        {
            if (getBoard()[i][j].getPiece().getColor() == player.getColor())
            {
                pos.setRow(i);
                pos.setColumn(j);
                positions.push_back(pos);
            }
            pos.setRow(0);
            pos.setColumn(0);
        }
    }
    return positions;
}

/**
 * @return vector<vector<Square>>
 */
vector<vector<Square>> getBoard()
{
    vector<vector<Square>> copyBoard;
    for (unsigned i = 0; i < sizeof (Diaballik::getBoard()); i++)
    {
        for (unsigned j = 0; j < sizeof (Diaballik::getBoard()); j++)
        {
            Piece p(Diaballik::getBoard()[i][j].getPiece().getColor(), Diaballik::getBoard()[i][j].getPiece().);
            Square sq();
            copyBoard.push_back(Square)
        }
    }
    return copyBoard;
}


/**
 * @param position
 * @return void
 */
void remove(Position position)
{
    return;
}

/**
 * @param position
 * @return Piece
 */
Piece getPiece(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return Diaballik::getBoard()[position.getRow()][position.getColumn()].getPiece();
}
