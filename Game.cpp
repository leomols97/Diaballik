/**
 * Project Diaballik
 */


#include "Game.h"
#include "Direction.h"
#include <iostream>

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

/**
 * @return void
 */
void initialize()
{
    Game game;
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
        Board().isInside(&p);
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
    if (!hasMoves(current)/*autre condition à rajouter s'il décide de ne pas utiliser tous ses mouvements*/) {
        Player provisoire = current;
        current = opponent;
        opponent = provisoire;
    }
}

/**
 * @return void
 */
void start()
{
    return BLABLA;
}

/**
 * @param selected
 * @return List<Move>
 */
vector<Move> getMoves(Position *selected)
{
    try
    {
        Board().isInside(selected);
    }
    catch (const exception e)
    {
        cerr << "La position sélectionnée ne fait pas partie du plateau de jeu. Réessayez : ";
    }
    /*if (selected == nullptr)
    {
        cerr << "La position selectionnée ne contient pas de pièce. Réessayez : ";
    }*/
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
        Board().getSquare(selected).isMyOwn(Game().getCurrent().getColor());
    }
    catch (const exception e)
    {
        cerr << "La pièce que vous avez sélectionnée ne vous appartient pas. Sélectionnez-en une autre :";
    }

    Piece piece(Board().getPiece(selected)->getColor());
    vector<Move> moves;
    if(Game().getCurrent().getNbMoves() == 1)
    {
        for(Direction dir )
        {
            if(Board().isInside(selected->next(dir)) && Board().isFree(selected->next(dir)))
            {

            }
        }
    }
    else if(Game().getCurrent().getNbMoves() == 2)
    {
        for(Direction dir )
        {
            if(Board().isInside(selected->next(dir)) && Board().isFree(selected->next(dir)))
            {

            }
        }
        for(Direction dir )
        {
            for(Direction dir2 ...)
            {
                if(Board().isInside(selected->next(dir)->next(dir2)) && Board().isFree(selected->next(dir)->next(dir2)))
                {

                }
            }
        }
    }
    return moves;

}

/**
 * @param move
 * @return void
 */
void Game::apply(Move move)
{
    Piece piece(Board().getPiece(move.getEnd())->getColor());
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
