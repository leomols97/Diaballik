/**
 * Project Diaballik
 */


#include "Game.h"
#include "Direction.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Diaballik;

/**
 * Game implementation
 */


Game::Game()
{
    Board board_(vector<vector<Square>> board_);
    Player current_(White), oponent(Black);
    Position selected_(int row, int column);
}

/**
 * @return void
 */
void Game::initialize()
{
    this->board_.initialize();
    //board.reserve(7);
    /*for (unsigned i = 0; i < this->board_.getBoard().size(); i++)
    {
        //board[i].reserve(7);
        for (unsigned j = 0; j < sizeof (this->board_.getBoard()[i].size()); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(Black);
                p.changeHasBall(true);
                this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 6 && j == 3)
            {
                Piece p(White);
                p.changeHasBall(true);
                this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 0)
            {
                Piece p(Black);
                this->board_.getBoard()[i][j].put(p);
            }
            else if (i == 6)
            {
                Piece p(White);
                this->board_.getBoard()[i][j].put(p);
            }
            else
            {
                Piece p;
                this->board_.getBoard()[i][j].put(p);
            }
        }
    }*/
}

bool Game::fairPlay()
{
    Position pos;
    bool foulGame = false;
    bool found = false;
    int count = 0;
    for(unsigned i = 0; i<board_.getBoard().size() && !found; i++)
    {
        if(board_.getBoard()[(i)][0].isMyOwn(opponent_.getColor()))
        {
            pos = {static_cast<int>(i), 0};
            found = true;
            if(board_.isInside({static_cast<int>(i)+1, 0})
                    && board_.isMyOwn({static_cast<int>(i)+1, 0}, current_.getColor()))
            {
                count++;
            }
            if(board_.isInside({static_cast<int>(i)-1, 0})
                    && board_.isMyOwn({static_cast<int>(i)-1, 0}, current_.getColor()))
            {
                count++;
            }
        }
    }

    for(unsigned i = 1; i<board_.getBoard().size() && found; i++)
    {
        found = false;
        for(unsigned j = 0; j<board_.getBoard().size(); j++)
        {
            if(board_.getBoard()[(j)][(i)].isMyOwn(opponent_.getColor()))
            {
                if(pos.getColumn()!=static_cast<int>(i)
                        && (pos.getRow()==static_cast<int>(j)
                            || pos.getRow()==static_cast<int>(j)+1
                            || pos.getRow()==static_cast<int>(j)-1))
                {
                    pos = {static_cast<int>(j),static_cast<int>(i)};
                    found = true;
                    if(board_.isInside({static_cast<int>(j)+1,static_cast<int>(i)})
                            && board_.isMyOwn({static_cast<int>(j)+1, static_cast<int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                    if(board_.isInside({static_cast<int>(j)-1, static_cast<int>(i)})
                            && board_.isMyOwn({static_cast<int>(j)-1, static_cast<int>(i)}, current_.getColor()))
                    {
                        count++;
                    }
                }
                if(i==board_.getBoard().size()-1
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
 * @param player
 * @return boolean
 */
/*bool foulGame(Player player)
{
      Si toutes les pièces collées à une pièce adverse ne peuvent pas faire de mouvement vers l'avant, c'est foulGame
      */
/*return false;
}*/

/**
 * @return boolean
 */
bool Game::isOver()
{
    for (unsigned i = 0; i < sizeof (Board().getBoard()); i++)
    {
        if (board_.getBoard()[0][i].getPiece().getColor() == White
                || Board().getBoard()[6][i].getPiece().getColor() == Black)
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
        board_.isInside(p);
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
    if (!isOver() && board_.isEmpty())
    {
        throw invalid_argument("il y a déjà une parti en cours");
    }
}

vector<Direction> Game::allDirections ()
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

vector<Move> Game::getMoves(){
    return getMoves(selected_);
}
/**
 * @param selected
 * @return List<Move>
 */
vector<Move> Game::getMoves(Position selected)
{
    /*try
    {
        board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        board_.getSquare(selected).isMyOwn(getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }*/

    Piece piece(Board().getPiece(selected).getColor());
    vector<Move> possibleEndingPositions;
    vector<Direction> directions;
    for (unsigned i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    if(getNbMoves(getCurrent()) == 1)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            if (board_.isInside(selected.next(selected, directions.at(i))))
            {
                Move move(board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                possibleEndingPositions.push_back(move);
            }
        }
    }
    else if(getNbMoves(getCurrent()) == 2)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            for (unsigned i = 0; i < 4; i++)
            {
                if (board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Move move(board_.getPiece(selected), selected, selected.next(selected, directions.at(i)));
                    possibleEndingPositions.push_back(move);
                }
            }
        }
    }
    return possibleEndingPositions;

}

vector<Piece> Game::getPossiblePasses(Position selected)
{
    /*try
    {
        board_.isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try
    {
        board_.isFree(selected);
    }
    catch (const exception e)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        board_.getSquare(selected).isMyOwn(getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }*/

    Piece startingPiece(board_.getPiece(selected).getColor());
    vector<Piece> possiblePasses;
    if (startingPiece.getHasBall())
    {
        vector<Direction> directions;
        for (unsigned i  = 0; i < allDirections().size(); i++)
        {
            directions.push_back(allDirections()[i]);
        }
        if(board_.getPiece(selected).canPassBall(selected))
        {
            Position endingPos = selected;
            for (unsigned i = 0; i < 4; i++)
            {
                if (board_.isInside(selected.next(selected, directions.at(i))))
                {
                    Piece endingPiece(board_.getPiece(selected.next(selected, directions.at(i))).getColor());
                    for (unsigned i = 0; i < board_.getBoard().size(); i++)
                    {
                        for (unsigned j = 0; i < board_.getBoard()[i].size(); j++)
                        {
                            if (startingPiece.getColor() == endingPiece.getColor())
                            {
                                endingPos = endingPos.next(endingPos, directions.at(i));
                                if (startingPiece.canPassBall(endingPos))
                                {
                                    possiblePasses.push_back(endingPiece);
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
    for (unsigned i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    for (unsigned i = 0; i < board_.getBoard().size(); i++)
    {
        for (unsigned i = 0; i < board_.getBoard()[i].size(); i++)
        {
            for (unsigned i = 0; i < 4; i++)
            {
                if (board_.isInside(selected.next(selected, directions.at(i)))
                        && board_.isFree(selected.next(selected, directions.at(i)))
                        && board_.isMyOwn(selected.next(selected, directions.at(i)), player.getColor()))
                {
                    nbMoves++;
                }
                if (board_.isInside(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && board_.isFree(selected.next(selected.next(selected, directions.at(i)), directions.at(i)))
                        && board_.isMyOwn(selected.next(selected.next(selected, directions.at(i)), directions.at(i)), player.getColor()))
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
    Piece piece(Board().getPiece(move.getStart()).getColor());
    if (board_.isFree(move.getEnd()))
    {
        board_.remove(move.getStart());
        board_.put(piece, move.getEnd());
    }
}

/**
 * @param move
 * @return void
 */
void Game::applyPass(Move move)
{
    Piece piece(board_.getPiece(move.getStart()).getColor());
    if (piece.canPassBall(move.getStart()))
    {
        board_.getPiece(move.getStart()).changeHasBall(false);
        board_.getPiece(move.getEnd()).changeHasBall(true);
    }
}

Piece Game::getSelected(int row, int column)
{
    select(row, column);
    return board_.getPiece(selected_);
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
        for (unsigned i = 0; i < sizeof (Board().getBoard()); i++)
        {
            if (board_.getBoard()[0][i].getPiece().getColor() == White)
            {
                winner.setColor(White);
            }
            if (board_.getBoard()[0][i].getPiece().getColor() == Black)
            {
                winner.setColor(Black);
            }
        }
    }
    return winner;
}
