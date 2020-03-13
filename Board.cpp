
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
    Position pos(0,0);
    for (unsigned i = 0; i < sizeof (Board().getBoard()); i++)
    {
        vector<Square> lign;
        for (unsigned j = 0; j < sizeof (Board().getBoard()); j++)
        {
            pos.setRow(i);
            pos.setColumn(j);
            Piece p(Board().getSquare(pos).getPiece()->getColor());
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

bool isInside(Position position)
{
    return position.getRow() > 0
            && position.getRow() < 6
            && position.getColumn() > 0
            && position.getColumn() < 6;
}

/**
 * @param position
 * @return boolean
 */
bool isFree(Position position)
{
    return Board().getPiece(position) == nullptr;  //il faut transformer Piece en pointeur
}

/**
 * @param piece
 * @param position
 * @return void
 */
void put(Piece piece, Position position)
{
    Board().getSquare(position).put(piece);
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> getTakenSquare(Player player)
{
    Position pos(0,0);
    vector<Position> positions;
    for (unsigned i = 0; i < sizeof(Board().getBoard()); i++)
    {
        for (unsigned j = 0; j < sizeof (sizeof(Board().getBoard())); j++)
        {
            pos.setRow(i);
            pos.setColumn(j);
            if (Board().getSquare(pos).getPiece()->getColor() == player.getColor())
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
    return this->board[position.getRow()][position.getColumn()];
}

/**
 * @return vector<vector<Square>>
 */
vector<vector<Square>> Board::getBoard()
{
    return this->board;
}


/**
 * @param position
 * @return void
 */
void remove(Position position)
{
    Board().getSquare(position).remove();
}

/**
 * @param position
 * @return Piece
 */
Piece * getPiece(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return Board().getSquare(position).getPiece();
}
