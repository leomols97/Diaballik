/**
 * Project Diaballik
 */


#include "Game.h"
#include "Direction.h"
#include <iostream>
#include <stdio.h>
#include <stdexcept>


using namespace std;
using namespace Diaballik;

/**
 * Game implementation
 */
Game::Game()
{
}

Game::~Game()
{
    delete &current_;
    delete &opponent_;
    delete &board_;
}

/**
 * This initializes a Game by initializing a board
 */
void Game::initialize()
{
    vector<vector<Square>> b(8);
    Board board(b);
    cout << board.getBoard().size() << "AAAA" << endl;
    Player current_(White), oponent(Black);
    Position selected_(int row, int column);

    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {
        board.getBoard()[i].reserve(7);
        for (unsigned int j = 0; j < sizeof (board.getBoard()[i].size()); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(Black);
                Piece().changeHasBall(true);
                board.getBoard()[i][j].put(p);
            }
            else if (i == 6 && j == 3)
            {
                Piece p(White);
                Piece().changeHasBall(true);
                board.getBoard()[i][j].put(p);
            }
            else if (i == 0 && j != 3)
            {
                Piece p(Black);
                board.getBoard()[i][j].put(p);
            }
            else if (i == 6 && j != 3)
            {
                Piece p(White);
                board.getBoard()[i][j].put(p);
            }
            else
            {
                Piece p(None);
                board.getBoard()[i][j].put(p);
            }
        }
    }

    //board.reserve(7);
    /*for (unsigned int i = 0; i < this->this->board_.getBoard().size(); i++)
    {
        //board[i].reserve(7);
        for (unsigned int j = 0; j < this->this->board_.getBoard()[i].size(); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(Black);
                p.changeHasBall(true);
                this->this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 6 && j == 3)
            {
                Piece p(White);
                p.changeHasBall(true);
                this->this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 0)
            {
                Piece p(Black);
                this->this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 6)
            {
                Piece p(White);
                this->this->board_.getBoard()[i][j].put(p);
            }
            else
            {
                Piece p;
                this->this->board_.getBoard()[i][j].put(p);
            }
        }
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

void Game::getPasses(vector<Position> list) const
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
}

bool Game::canPassBall(Position pos)
{
    bool found = false;
    vector<Position> passPositions;
    getPasses(passPositions);
    for (size_t i {0}; i < (passPositions.size()) && !found; i++)
    {
        if (pos.getRow() == passPositions.at(i).getRow()  && pos.getColumn() == passPositions.at(i).getColumn())
        {
            found = true;
        }
    }
    return found && Player().getHasPass();
}


bool Game::fairPlay()
{
    Position pos;
    bool foulGame = false;
    bool found = false;
    int count = 0;
    for(unsigned int i = 0; i < this->board_.getBoard().size() && !found; i++)
    {
        if(this->board_.getBoard()[(i)][0].isMyOwn(opponent_.getColor()))
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
            if(this->board_.getBoard()[(j)][(i)].isMyOwn(opponent_.getColor()))
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
        if (this->board_.getBoard()[0][i].getPiece().getColor() == White
                || this->board_.getBoard()[6][i].getPiece().getColor() == Black)
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
        cout << "La position que vous essayez de sélectionner n'est pas sur le plateau de jeu";
    }
    this->selected_ = Position(row, column);
}

/**
 * @return void
 */
void Game::swapPlayers()
{
    if (!hasMoves(current_))
        /*autre condition à rajouter s'il décide de ne pas utiliser tous ses mouvements*/
        // ->Il "suffit", dans le controleur, de recevoir une commande "tour fini"
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
    for (unsigned int i = 0; i < 8; i++)
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
        this->board_.getSquare(selected).isMyOwn(getCurrent().getColor());
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
    if(getNbMoves(getCurrent()) == 1)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            if (this->board_.isInside(selected.next(selected, directions.at(i))))
            {
                Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                possibleEndingPositions.push_back(move);
            }
        }
    }
    else if(getNbMoves(getCurrent()) == 2)
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            for (unsigned int i = 0; i < 4; i++)
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Move move(this->board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                    possibleEndingPositions.push_back(move);
                }
            }
        }
    }
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
        this->board_.getSquare(selected).isMyOwn(getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }

    Piece startingPiece(this->board_.getPiece(selected).getColor());
    vector<Position> possiblePasses;
    if (startingPiece.getHasBall())
    {
        vector<Direction> directions;
        for (unsigned int i  = 0; i < allDirections().size(); i++)
        {
            directions.push_back(allDirections()[i]);
        }
        /*if(this->board_.getPiece(selected).canPassBall(selected))
        {*/
        if (canPassBall(selected))
        {
            Position endingPos = selected;
            for (unsigned int i = 0; i < 4; i++)
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Piece endingPiece(this->board_.getPiece(selected.next(selected, directions.at(i))).getColor());
                    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
                    {
                        for (unsigned int j = 0; i < this->board_.getBoard()[i].size(); j++)
                        {
                            if (startingPiece.getColor() == endingPiece.getColor())
                            {
                                endingPos = endingPos.next(endingPos, directions.at(i));
                                if (canPassBall(endingPos))
                                {
                                    possiblePasses.push_back(endingPos);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return possiblePasses;
}


/**
 * @return int
 */
int Game::getNbMoves(Player player)
{
    int nbMoves = 0;
    Position selected;
    vector<Direction> directions;
    for (unsigned int i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
    {
        for (unsigned int i = 0; i < this->board_.getBoard()[i].size(); i++)
        {
            for (unsigned int i = 0; i < 4; i++)
            {
                if (this->board_.isInside(selected.next(selected, directions.at(i)))
                        && this->board_.isFree(selected.next(selected, directions.at(i)))
                        && this->board_.isMyOwn(selected.next(selected, directions.at(i)), player.getColor()))
                {
                    nbMoves++;
                }
                if (this->board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && this->board_.isMyOwn(selected.next(selected.next(selected, directions.at(i)), directions.at(i)), player.getColor()))
                {
                    nbMoves++;
                }
            }
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
        this->board_.remove(move.getStart());
        this->board_.put(piece, move.getEnd());
    }
}

/**
 * @param move
 * @return void
 */
void Game::applyPass(Move move)
{
    Piece piece(this->board_.getPiece(move.getStart()).getColor());
    if (canPassBall(move.getEnd()))
    {
        this->board_.getPiece(move.getStart()).changeHasBall(false);
        this->board_.getPiece(move.getEnd()).changeHasBall(true);
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
    return getNbMoves(player) > 0;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    //rajouter condition de anti-jeu
    Player winner;
    if (!fairPlay())
    {
        for (unsigned int i = 0; i < this->board_.getBoard().size(); i++)
        {
            if (this->board_.getBoard()[0][i].getPiece().getColor() == White)
            {
                winner.setColor(White);
            }
            if (this->board_.getBoard()[0][i].getPiece().getColor() == Black)
            {
                winner.setColor(Black);
            }
        }
    }
    return winner;
}
