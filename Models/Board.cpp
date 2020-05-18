
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
    for (unsigned int i = 0; i < boardLength_; i++)
    {
        vector<Piece> lign;
        for (unsigned int j = 0; j < boardLength_; j++)
        {
            Piece p(None);
            lign.push_back(p);
        }
        board.push_back(lign);
    }
    board_ = board;
}

void Board::initializeOriginal()
{
    cout << "AAAA" << endl;
    vector<vector<Piece>> row;
    for (unsigned int i = 0; i < boardLength_; i++)
    {
        cout << "BBBB" << endl;
        vector<Piece> columns;
        for (unsigned int j = 0; j < boardLength_; j++)
        {
            Position position(i, j);
            try
            {
                cout << "i : " << i << " ; j : " << j << endl;
                if (i == 0 && j == 3)
                {
                    cout << "DDDD" << endl;
                    Piece p(BlackWithBall);
                    columns.push_back(p);
                    //p.changeHasBall(true);
                    //this->board_.at(i).at(j).setColor(BlackWithBall);

                    //this->opponent_.addPieceToPlayer(p);
                    //cout << p.getColor() << endl;
                }
                else if (i == boardLength_ - 1 && j == 3)
                {
                    cout << "EEEE" << endl;
                    Piece p(WhiteWithBall);
                    columns.push_back(p);
                    //p.changeHasBall(true);
                    //this->board_.at(i).at(j).setColor(WhiteWithBall);
                    //this->current_.addPieceToPlayer(p);
                }
                else if (i == 0 && j != 3)
                {
                    Piece p(Black);
                    columns.push_back(p);
                    //this->put(Black, position);
                    //cout << "this->board_[i][j].getColor : " << this->board_[i][j].getColor() << endl;
                    //this->board_[i][j].setColor(Black);
                    cout << "FFFF" << endl;
                    //this->opponent_.addPieceToPlayer(p);
                }
                else if (i == boardLength_ - 1 && j != 3)
                {
                    cout << "GGGG" << endl;
                    Piece p(White);
                    columns.push_back(p);
                    //this->board_.at(i).at(j).setColor(White);
                    //this->current_.addPieceToPlayer(p);
                }
                else
                {
                    cout << "HHHH" << endl;
                    Piece p(None);
                    columns.push_back(p);
                    //this->board_.at(i).at(j).setColor(None);
                }
                row.push_back(columns);
            }
            catch (exception e)
            {
                cout << e.what() << " i : " << i << " ; j : " << j <<  endl;
            }
        }
    }
}

void Board::initializeVariante()
{
    for (unsigned int i = 0; i < boardLength_; i++)
    {
        for (unsigned int j = 0; j < boardLength_; j++)
        {
            if (i == 0 && j == 3)
            {
                //Piece p(BlackWithBall);
                //p.changeHasBall(true);
                this->board_[i][j].setColor(BlackWithBall);
                //this->opponent_.addPieceToPlayer(p);
                //cout << p.getColor() << endl;
            }
            else if (i == boardLength_ - 1 && j == 3)
            {
                //Piece p(WhiteWithBall);
                //p.changeHasBall(true);
                this->board_[i][j].setColor(WhiteWithBall);
                //this->current_.addPieceToPlayer(p);
            }
            else if ((i == 0 && j == 1) || (i == 0 && j == boardLength_ - 2))
            {
                //Piece p(White);
                this->board_[i][j].setColor(White);
                //this->current_.addPieceToPlayer(p);
            }
            else if ((i == boardLength_ - 1 && j == 1) || (i == boardLength_ - 1 && j == boardLength_ - 2))
            {
                //Piece p(Black);
                this->board_[i][j].setColor(Black);
                //this->current_.addPieceToPlayer(p);
            }
            else if (i == 0 && j != 3)
            {
                //Piece p(Black);
                this->board_[i][j].setColor(Black);
                //this->opponent_.addPieceToPlayer(p);
            }
            else if (i == boardLength_ - 1 && j != 3)
            {
                //Piece p(White);
                this->board_[i][j].setColor(White);
                //this->current_.addPieceToPlayer(p);
            }
            else
            {
                //Piece p(None);
                this->board_[i][j].setColor(None);
            }
        }
    }
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
bool Board::isInside(Position &position) const
{
    /*return ((pos.getColumn() >= 0 && static_cast<unsigned>(pos.getColumn()) < board_.size() )
            && static_cast<unsigned>(pos.getRow()) < board_[0].size() && pos.getRow() >= 0);*/
    cout << "boardLength_ = " << boardLength_ << endl;
    return position.getRow() > -1
            && position.getRow() < boardLength_
            && position.getColumn() > - 1
            && position.getColumn() < boardLength_;
}

/**
 * @param position
 * @return Piece
 */
Piece Board::getPiece(Position &position)
{
    //cout << "pos row : " << position.getRow();
    //cout << " ; col : " << position.getColumn() << endl;
    if (position.getRow() == 0 && position.getColumn() == 6)
    {
        //cout << "AZERTYU";
    }
    if (!isInside(position))
    {
        cout << " row : " << position.getRow() << " ; column : " << position.getColumn();
        throw invalid_argument("La position n'est pas dans le plateau de jeu !");
    }
    cout << "position.getRow() = " << position.getRow() << " ; position.getColumn() = " << position.getColumn() << endl;
    Piece p = this->board_[position.getRow()][position.getColumn()];
    //cout << "this->board_[position.getRow()][position.getColumn()] : " << this->board_.at(position.getRow()).at(position.getColumn()) << endl;
    return p;
}

/**
 * @param position
 * @return boolean
 */
bool Board::isFree(Position &position)
{
    if (!isInside(position))
    {
        throw invalid_argument("La position n'est pas dans le plateau de jeu !\n");
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
void Board::put(Color &color, Position &position)
{
    this->board_[position.getRow()][position.getColumn()].setColor(color);
}

bool Board::isMyOwn(Position &position, Color &color) // gérer les couleurs avec white et whitewithball et black et blackwithball
{
    return getPiece(position).getColor() == color;
}

/**
 * @param player
 * @return List<Position>
 */
vector<Position> Board::getTakenSquares(Player &player)
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


/**
 * @param position
 * @return void
 */
void Board::remove(Position &position)
{
    this->board_[position.getRow()][position.getColumn()].setColor(None);
}

void Board::applyPass(Position &positionThatGives, Position &positionThatReceives, Color &playerColor)
{
    if(playerColor == White)
    {
        this->board_[positionThatGives.getRow()][positionThatGives.getColumn()].setColor(White);
        this->board_[positionThatReceives.getRow()][positionThatReceives.getColumn()].setColor(WhiteWithBall);
    }
    else if(playerColor == Black)
    {
        this->board_[positionThatGives.getRow()][positionThatGives.getColumn()].setColor(Black);
        this->board_[positionThatReceives.getRow()][positionThatReceives.getColumn()].setColor(BlackWithBall);
    }
}
