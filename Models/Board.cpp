
/**
 * Project Diaballik
 */


#include "Board.h"

using namespace Diaballik;

/**
 * Board implementation
 */
//Board::Board()
//{
    /*cout << "Board default " << endl;
    cout << "Board()" << endl;
    //board.reserve(7);
    Position pos(0,0);
    for (unsigned int i = 0; i < this->board_.size(); i++)
    {
        //board[i].reserve(7);
        vector<Square> lign;
        for (unsigned int j = 0; j < this->board_[i].size(); j++)
        {
            Piece p(None);
            Square sq(p);
            lign.push_back(sq);
        }
        this->board_.push_back(lign);
    }*/
//}

/**
 * Default constructor needed by the constructor of Game
 * @brief Board::Board
 */

Board::Board(unsigned int boardLength) :
    board_(boardLength),
    boardLength_(boardLength)
{
    //boardLength_ = boardLength;
    //board.reserve(7);
    //Position pos(0,0);
    vector<vector<Square>> board;
    for (unsigned int i = 0; i < boardLength_; i++)
    {
        //board[i].reserve(7);
        vector<Square> lign;
        for (unsigned int j = 0; j < boardLength_; j++)
        {
            Piece p(None);
            Square sq(p);
            lign.push_back(sq);
        }
        board.push_back(lign);
    }
    board_ = board;
    cout << "Good board " << boardLength_ << endl;
    cout << "Board(int length)" << endl;
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
    return position.getRow() > 0
            && position.getRow() < 6
            && position.getColumn() > 0
            && position.getColumn() < 6;
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
    return getSquare(position).getPiece();
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
    return getPiece(position).isReal();
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
void Board::put(Piece piece, Position position)
{
    getSquare(position).put(piece);
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

Square Board::getSquare(Position position) const
{
    return this->board_[position.getRow()][position.getColumn()];
}

/**
 * @return vector<vector<Square>>
 */



/**
 * @param position
 * @return void
 */
void Board::remove(Position position)
{
    getSquare(position).remove();
}
