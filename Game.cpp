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
    Board board(vector<vector<Square>> board);
    Player current(White), oponent(Black);
    Position selected(int row, int column);
}

auto get(unsigned i)
{

}

/**
 * @return void
 */
void Game::initialize()
{
    //board.reserve(7);
    for (unsigned i = 0; i < Board().getBoard().size(); i++)
    {
        //board[i].reserve(7);
        for (unsigned j = 0; j < sizeof (Board().getBoard()[i].size()); j++)
        {
            if (i == 0 && j == 3)
            {
                Piece p(Black);
                Piece().changeHasBall(&p);
                Board().getBoard()[i][j].put(&p);
            }
            else if (i == 6 && j == 3)
            {
                Piece p(White);
                Piece().changeHasBall(&p);
                Board().getBoard()[i][j].put(&p);
            }
            else if (i == 0)
            {
                Piece p(Black);
                Board().getBoard()[i][j].put(&p);
            }
            else if (i == 6)
            {
                Piece p(White);
                Board().getBoard()[i][j].put(&p);
            }
            else
            {
                Piece p;
                Board().getBoard()[i][j].put(&p);
            }
        }
    }
}

/**
 * @param player
 * @return boolean
 */
bool foulGame(Player player)
{
    /**
      Si toutes les pièces collées à une pièce adverse ne peuvent pas faire de mouvement vers l'avant, c'est foulGame
      */
    return false;
}

/**
 * @return boolean
 */
bool isOver()
{
    for (unsigned i = 0; i < sizeof (Board().getBoard()); i++)
    {
        if (Board().getBoard()[0][i].getPiece().getColor() == White
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
        Board().isInside(p);
    }
    catch (const exception e)
    {
        cout << "La position que vous essayez de sélectionner n'est pas sur le plateau de jeu";
    }
    this->selected = Position(row, column);
}

/**
 * @return void
 */
void Game::swapPlayers()
{
    if (!hasMoves(current))
        /*autre condition à rajouter s'il décide de ne pas utiliser tous ses mouvements*/
        // ->Il "suffit", dans le controleur, de recevoir une commande "tour fini"
    {
        Player provisoire = current;
        current = opponent;
        opponent = provisoire;
    }
}

/**
 * @return void
 */
void Game::start()
{
    if (!isOver() && board.isEmpty())
    {
        throw invalid_argument("il y a déjà une parti en cours");
    }
}

vector<Direction> allDirections ()
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

/**
 * @param selected
 * @return List<Move>
 */
vector<Position> getMoves(Position selected)
{
    try
    {
        Board().isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    try 
    {
        Board().isFree(selected);
    } 
    catch (const exception e) 
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }
    try
    {
        Board().getSquare(&selected).isMyOwn(Game().getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }

    Piece piece(Board().getPiece(selected).getColor());
    vector<Position> possibleEndingPositions;
    vector<Direction> directions;
    for (unsigned i  = 0; i < allDirections().size(); i++)
    {
        directions.push_back(allDirections()[i]);
    }
    if(Game().getCurrent().getNbMoves() == 1)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            if (Board().isInside(selected.next(selected, directions.at(i))))
            {
                possibleEndingPositions.push_back(selected.next(selected, directions.at(i)));
            }
        }
    }
    else if(Game().getCurrent().getNbMoves() == 2)
    {
        for (unsigned i = 0; i < 4; i++)
        {
            for (unsigned i = 0; i < 4; i++)
            {
                if (Board().isInside(selected.next(selected, directions.at(i))))
                {
                    possibleEndingPositions.push_back(selected.next(selected, directions.at(i)));
                }
            }
        }
    }
    return possibleEndingPositions;

}

/**
 * @param move
 * @return void
 */
void Game::apply(Move move)
{
    Piece piece(Board().getPiece(move.getEnd()).getColor());
    if (board.isFree(move.getEnd())) {
        board.remove(move.getStart());
        board.put(&piece, move.getEnd());
    }
}

/**
 * @param player
 * @return boolean
 */
bool hasMoves(Player player)
{
    return player.getNbMoves() > 0;
}

/**
 * @return Player
 */
Player Game::getWinner()
{
    //rajouter condition de anti-jeu
    return this->current;
}
