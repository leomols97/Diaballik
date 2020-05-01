/**
 * Project Diaballik
 */


#include "Game.h"

using namespace Diaballik;


/**
 * Game implementation
 */
Game::Game() :
    board_(7),
    current_(White),
    opponent_(Black),
    selected_(0, 0)
{}

/*Game::~Game()
{
    delete &current_;
    delete &opponent_;
    delete &board_;
}*/

/**
 * This initializes a Game by initializing a board
 */
void Game::initialize()
{
    this->board_.initialize();
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        for (unsigned int j = 0; j < this->board_.getBoard()[i].size(); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(BlackWithBall);
                //p.changeHasBall(true);
                //this->board_.getPiece(pos).setColor(BlackWithBall);
                this->opponent_.addPieceToPlayer(p);
                //cout << p.getColor() << endl;
            }
            else if (i == this->board_.getBoard().size() - 1 && j == 3)
            {
                Piece p(WhiteWithBall);
                //p.changeHasBall(true);
                //this->board_.getPiece(pos).setColor(WhiteWithBall);
                this->current_.addPieceToPlayer(p);
            }
            else if (i == 0 && j != 3)
            {
                Piece p(Black);
                //this->board_.getPiece(pos).setColor(Black);
                this->opponent_.addPieceToPlayer(p);
            }
            else if (i == this->board_.getBoard().size() - 1 && j != 3)
            {
                Piece p(White);
                //p.setSelected(true);
                //this->board_.getPiece(pos).setColor(White);
                this->current_.addPieceToPlayer(p);
            }
            else
            {
                Piece p(None);
                this->board_.getBoard()[i][j].setColor(None);
            }
        }
    }
    /*for (unsigned int i = 0; i < this->current_.getPieces().size(); i++)
    {
        cout << this->current_.getPieces().at(i).getColor() << endl;
    }
    for (unsigned int i = 0; i < this->opponent_.getPieces().size(); i++)
    {
        cout << this->opponent_.getPieces().at(i).getColor() <<endl;
    }*/
}

/**
 * Verifies if a piece can pass the ball to
 * @return bool
 */
/*bool Game::canPassBall(Piece pieceThatGives, Position pos)
{
    //Piece piece(this->board_.getPiece(pos));
    Player player(pieceThatGives.getColor());
    bool canPass = false;
    if(player.getHasPass())
    {
        Position posHD(pos.getRow(), pos.getColumn());
        Position posHG(pos.getRow(), pos.getColumn());
        Position posBD(pos.getRow(), pos.getColumn());
        Position posBG(pos.getRow(), pos.getColumn());
        Position posB(pos.getRow(), pos.getColumn());
        Position posH(pos.getRow(), pos.getColumn());
        Position posD(pos.getRow(), pos.getColumn());
        Position posG(pos.getRow(), pos.getColumn());
        if(pieceThatGives.getHasBall())
        {
            for (int i = 0; i < 7; i++)
            {
                if(this->board_.isInside(posD) && this->board_.isInside(posG) &&
                        this->board_.isInside(posB) && this->board_.isInside(posH) &&
                        this->board_.isInside(posHD) && this->board_.isInside(posHG) &&
                        this->board_.isInside(posBD) && this->board_.isInside(posBG))
                {
                    posHD.setRow(posHD.getRow()+i);
                    posHD.setColumn(posHD.getColumn()+i);
                    posHG.setRow(posHG.getRow()+i);
                    posHG.setColumn(posHG.getColumn()-i);
                    posBD.setRow(posBG.getRow()-i);
                    posBD.setColumn(posBD.getColumn()+i);
                    posBG.setRow(posBG.getRow()-i);
                    posBG.setColumn(posBG.getColumn()-i);
                    posH.setColumn(posH.getColumn()+i);
                    posB.setColumn(posH.getColumn()-i);
                    posD.setRow(posD.getRow()+i);
                    posG.setRow(posD.getRow()-i);
                    if(this->board_.isMyOwn(posD, pieceThatGives.getColor()) || this->board_.isMyOwn(posG, pieceThatGives.getColor()) ||
                            this->board_.isMyOwn(posB, pieceThatGives.getColor()) || this->board_.isMyOwn(posH, pieceThatGives.getColor()) ||
                            this->board_.isMyOwn(posHD, pieceThatGives.getColor()) || this->board_.isMyOwn(posHG, pieceThatGives.getColor()) ||
                            this->board_.isMyOwn(posBD, pieceThatGives.getColor()) || this->board_.isMyOwn(posBG, pieceThatGives.getColor()))
                    {
                        canPass = true;
                    }
                }
            }
        }
    }
    return canPass;
}

void Game::passBall(Piece pieceThatReceive, Position pos)
{
    if(canPassBall(pieceThatReceive, pos))
    {
        this->board_.getPiece(pos).changeHasBall(false);
        pieceThatReceive.changeHasBall(true);
    }
}*/

/*void Game::passBall(Piece pieceThatGives, Position pos)
{
    if(pieceThatGives.canPassBall(pos))
    {
        pieceThatGives.changeHasBall(false);
        this->board_.getPiece(pos).changeHasBall(true);
        //pieceThatReceive.changeHasBall(true);
    }
}*/

/*void Game::getPasses(vector<Position> list) const
{
    for (int dirInt = 1; dirInt <= 8; dirInt++)
    {
        bool ok = true;
        const Direction dir = static_cast<Direction>(dirInt);
        Position posNext = selected_.next(selected_, dir);

        while (ok)
        {
            ok = this->board_.isInside(posNext) && !this->board_.isMyOwn(posNext, opponent_.getColor());

            if (ok && this->board_.isMyOwn(posNext, current_.getColor()))
            {
                list.push_back(Position(posNext.getRow(), posNext.getColumn()));
                posNext = posNext.next(posNext, dir);
                ok = this->board_.isInside(posNext) && !this->board_.isMyOwn(posNext, opponent_.getColor());
            }

            if (ok && this->board_.isFree(posNext))
            {
                posNext = posNext.next(posNext, dir);
            }
        }
    }
}*/

bool Game::canPassBall(Position pos)
{
    bool found = false;
    for (unsigned i = 0; i < allDirections().size(); i++)
        //for (size_t i {0}; i < (passPositions.size()) && !found; i++)
    {
        Position posNext = pos;
        Position posEnd = posNext.next(posNext, allDirections().at(i));
        if (this->board_.getPiece(pos).getColor() == WhiteWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == White)
                {
                    found = true;
                }
                posNext = pos.next(pos, allDirections().at(i));
                posEnd = posEnd.next(posEnd, allDirections().at(i));
            }
            while (this->board_.isInside(posEnd));
        }
        if (this->board_.getPiece(pos).getColor() == BlackWithBall)
        {
            do
            {
                if (this->board_.getPiece(posNext).getColor() == Black)
                {
                    found = true;
                }
                posNext = pos.next(pos, allDirections().at(i));
                posEnd = posEnd.next(posEnd, allDirections().at(i));
            }
            while (this->board_.isInside(posEnd));
        }
    }
    return found; //&& current_.getHasPass();
}


bool Game::fairPlay()
{
    Position pos(0,0);
    bool foulGame = false;
    bool found = false;
    int count = 0;
    for(unsigned int i = 0; i < this->board_.getBoard().size() && !found; i++)
    {
        pos.setRow(i);
        pos.setColumn(0);
        //if(this->board_.getBoard()[(i)][0].isMyOwn(opponent_.getColor()))
        if(this->board_.isMyOwn(pos, opponent_.getColor()))
        {
            pos = {static_cast<int>(i), 0};
            found = true;
            if(this->board_.isInside({static_cast<int>(i)+1, 0})
                    && this->board_.isMyOwn({static_cast<int>(i)+1, 0}, current_.getColor()))
            {
                count++;
            }
            if(this->board_.isInside({static_cast<int>(i)-1, 0})
                    && this->board_.isMyOwn({static_cast<int>(i)-1, 0}, current_.getColor()))
            {
                count++;
            }
        }
    }

    for(unsigned int i = 1; i < this->board_.getBoard().size() && found; i++)
    {
        found = false;
        for(unsigned int j = 0; j < this->board_.getBoard().size(); j++)
        {
            pos.setRow(j);
            pos.setRow(i);
            if(this->board_.isMyOwn(pos, opponent_.getColor()))
            {
                if(pos.getColumn()!=static_cast<int>(i)
                        && (pos.getRow()==static_cast<int>(j)
                            || pos.getRow()==static_cast<int>(j)+1
                            || pos.getRow()==static_cast<int>(j)-1))
                {

                    pos = {static_cast<int>(j),static_cast<int>(i)};
                    found = true;
                    if(this->board_.isInside({static_cast<int>(j)+1,static_cast<int>(i)})
                            && this->board_.isMyOwn({static_cast<int>(j)+1, static_cast<int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                    if(this->board_.isInside({static_cast<int>(j)-1, static_cast<int>(i)})
                            && this->board_.isMyOwn({static_cast<int>(j)-1, static_cast<int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                }
                if(i==this->board_.getBoard().size()-1
                        && found
                        && count>=3)
                {
                    foulGame=true;
                }
            }
        }
    }
    return foulGame;
}

/**
 * @return boolean
 */
bool Game::isOver()
{
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        Position posW(0, i);
        Position posB(this->board_.getBoard().size() - 1, i);
        if (this->board_.getPiece(posW).getColor() == WhiteWithBall
                || this->board_.getPiece(posB).getColor() == BlackWithBall)
        {
            return true;
        }
    }
    return false;
}

/**
 * @param row
 * @param column
 * @return void
 */
void Game::select(int row , int column)
{
    Position p(row, column);
    try
    {
        this->board_.isInside(p);
    }
    catch (const exception e)
    {
        cout << "La position que vous essayez de sélectionnée n'est pas sur le plateau de jeu";
    }
    this->selected_ = Position(row, column);
}

/**
 * @return void
 */
void Game::swapPlayers()
{
    {
        Player provisoire = current_;
        current_ = opponent_;
        opponent_ = provisoire;
    }
}

/**
 * @return void
 */
void Game::start()
{
    if (!isOver() && this->board_.isEmpty())
    {
        throw invalid_argument("il y a déjà une parti en cours");
    }
}

vector<Direction> Game::allDirections ()
{
    vector<Direction> dirs;
    dirs.push_back(Direction::N);
    dirs.push_back(Direction::S);
    dirs.push_back(Direction::E);
    dirs.push_back(Direction::O);
    dirs.push_back(Direction::NE);
    dirs.push_back(Direction::SE);
    dirs.push_back(Direction::NO);
    dirs.push_back(Direction::SO);
    return dirs;
}

vector<Move> Game::getMoves(){
    return getMoves(selected_);
}
/**
 * @param selected
 * @return List<Move>
 */
vector<Move> Game::getMoves(Position selected)
{
    try
    {
        this->board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        this->board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        //this->board_.getSquare(selected).isMyOwn(getCurrent().getColor());
        this->board_.isMyOwn(selected, this->getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }

    Piece piece(this->board_.getPiece(selected).getColor());
    vector<Move> possibleEndingPositions;
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    //if(getNbMoves(selected) == 1)
    {
        for (unsigned int i = 0; i < directions.size(); i++)
        {
            if (this->board_.isInside(selected.next(selected, directions.at(i)))
                    && this->board_.isFree(selected.next(selected, directions.at(i))))
            {
                Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                possibleEndingPositions.push_back(move);
            }
        }
    }
    /*else if(getNbMoves(getCurrent()) == 2)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            for (unsigned int i = 0; i < 8; i++) //Car il y a 8 Moves possibles
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                    possibleEndingPositions.push_back(move);
                }
            }
        }
    }*/
    return possibleEndingPositions;

}

vector<Position> Game::getPossiblePasses(Position selected)
{
    try
    {
        this->board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        this->board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        this->board_.isMyOwn(selected, getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }
    vector<Position> passPositions;
    for (unsigned i = 0; i < allDirections().size(); i++)
    {
        Position posNext = selected;
        Position posEnd = posNext.next(posNext, allDirections().at(i));
        if (this->board_.getPiece(selected).getColor() == WhiteWithBall)
        {
            do
            {
                posEnd = posEnd.next(posEnd, allDirections().at(i));
                if (this->board_.getPiece(posNext).getColor() == White)
                {
                    passPositions.push_back(posNext);
                }
                posNext = selected.next(selected, allDirections().at(i));
                //cout << "posNext row : " << posNext.getRow();
                //cout << " ; col : " << posNext.getColumn() << endl;
            }
            while (this->board_.isInside(posEnd));
        }
        if (this->board_.getPiece(selected).getColor() == BlackWithBall)
        {
            do
            {
                posEnd = posEnd.next(posEnd, allDirections().at(i));
                if (this->board_.getPiece(posNext).getColor() == Black)
                {
                    passPositions.push_back(posNext);
                }
                posNext = selected.next(selected, allDirections().at(i));
            }
            while (this->board_.isInside(posEnd));
        }
    }
    for (unsigned int i = 0; i < passPositions.size(); i++)
    {
        passPositions.erase(passPositions.begin() + i);
    }
    return passPositions;
}


/**
 * @return int
 */
int Game::getNbMoves(Player player)
{
    int nbMoves = 0;
    Position selected(0, 0);
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        for (unsigned int i = 0; i < this->board_.getBoard()[i].size(); i++)
        {
            for (unsigned int i = 0; i < 8; i++)
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i)))
                        && this->board_.isFree(selected.next(selected, directions.at(i)))
                        && this->board_.isMyOwn(selected, player.getColor()))
                {
                    nbMoves++;
                }
                if (this->board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isMyOwn(selected, player.getColor()))
                {
                    nbMoves++;
                }
            }
        }
    }
    return nbMoves;
}

int Game::getNbMoves(Position selected)
{
    int nbMoves = 0;
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned int i = 0; i < 8; i++)
    {
        if (this->board_.isInside(selected.next(selected, directions.at(i)))
                && this->board_.isFree(selected.next(selected, directions.at(i))))
        {
            nbMoves++;
        }
        if (this->board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                && this->board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i))))
        {
            nbMoves++;
        }
    }
    return nbMoves;
}

/**
 * @param move
 * @return void
 */
void Game::apply(Move move)
{
    Piece piece(this->board_.getPiece(move.getStart()).getColor());
    if (this->board_.isFree(move.getEnd()))
    {
        this->board_.put(current_, move.getEnd());
        this->board_.remove(move.getStart());
        current_.setNbMoves(current_.getNbMoves()-1);
    }
}

/**
 * @param move
 * @return void
 */
void Game::applyPass(Position positionThatGives, Position positionThatReceives)
{
    if (canPassBall(positionThatGives))
    {
        this->board_.applyPass(positionThatGives, positionThatReceives, this->getCurrent().getColor());
        current_.setHasPass(false);
    }
}


Piece Game::getSelected(int row, int column)
{
    select(row, column);
    return this->board_.getPiece(selected_);
}

/**
 * @param player
 * @return boolean
 */
bool Game::hasMoves(Player player)
{
    return player.getNbMoves() > 0;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    Player winner(None); //Ajoute condition de anti-jeu
    if (!fairPlay())
    {
        for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
        {
            if (this->board_.getBoard()[0][i].getColor() == White)
            {
                winner.setColor(White);
            }
            if (this->board_.getBoard()[0][i].getColor() == Black)
            {
                winner.setColor(Black);
            }
        }
    }
    return winner;
}

void Game::changePlayer()
{
    if (current_.getColor() == White)
    {
        Player tmp(White);
        tmp = opponent_;
        opponent_ = current_;
        current_ = tmp;
    }
    else
    {
        Player tmp(Black);
        tmp = opponent_;
        opponent_ = current_;
        current_ = tmp;
    }
}
