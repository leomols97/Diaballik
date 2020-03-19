
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
            pos.setRow(i);
            pos.setColumn(j);
            if (i == 0)
            {
                Piece p(Black);
                Square sq(&p);
                lign.push_back(sq);
            }
            else if (i == 6)
            {
                Piece p(White);
                Square sq(&p);
                lign.push_back(sq);
            }
            else
            {
                Piece p;
                Square sq(&p);
                lign.push_back(sq);
            }
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
 * @return Piece
 */
Piece getPiece(Position position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    return Board().getSquare(&position).getPiece();
}

/**
 * @param position
 * @return boolean
 */
bool isFree(Position position)
{
    return Board().getPiece(&position) == nullptr;  //il faut transformer Piece en pointeur
}

/**
 * @param piece
 * @param position
 * @return void
 */
void put(Piece piece, Position position)
{
    Board().getSquare(&position).put(&piece);
}

bool isMyOwn(Position position, Color color)
{
    return Board().getPiece(&position).getColor() == &color;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> getTakenSquare(Player *player)
{
    Position pos(0,0);
    vector<Position> positions;
    for (unsigned i = 0; i < sizeof(Board().getBoard()); i++)
    {
        for (unsigned j = 0; j < sizeof (sizeof(Board().getBoard())); j++)
        {
            pos.setRow(i);
            pos.setColumn(j);
            if (Board().isMyOwn(&pos, player->getColor()))
            {
                positions.push_back(pos);
            }
            pos.setRow(0);
            pos.setColumn(0);
        }
    }
    return positions;
}

Square Board::getSquare(Position *position)
{
    return this->board[position->getRow()][position->getColumn()];
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
    Board().getSquare(&position).remove();
}
