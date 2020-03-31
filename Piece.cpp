/**
 * Project Diaballik
 */

#include "Piece.h"
#include "Player.h"
#include "Color.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Piece implementation
 */

Piece::Piece()
{
    this->real_ = false;
}

/**
 * @param color
 */
Piece::Piece(Color color)
{

    this->color_ = color;
    this->real_ = true;
    this->hasBall_ = false;
}

/**
 * @return boolean
 */
/*bool Piece::canPassBall(Position pos)
{
    Player player(color_);
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
        if(getHasBall())
        {
            for (unsigned i = 0; i < 7; i++)
            {
                if(board.isInside(posD) && board.isInside(posG) &&
                        board.isInside(posB) && board.isInside(posH) &&
                        board.isInside(posHD) && board.isInside(posHG) &&
                        board.isInside(posBD) && board.isInside(posBG))
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
                    if(board.isMyOwn(posD, getColor()) || board.isMyOwn(posG, getColor()) ||
                            board.isMyOwn(posB, getColor()) || board.isMyOwn(posH, getColor()) ||
                            board.isMyOwn(posHD, getColor()) || board.isMyOwn(posHG, getColor()) ||
                            board.isMyOwn(posBD, getColor()) || board.isMyOwn(posBG, getColor()))
                    {
                        canPass = true;
                    }
                }
            }
        }
    }
    return canPass;
}*/

/*void Piece::passBall(Board board, Piece pieceThatGives, Position pos)
{
    if(pieceThatGives.canPassBall(board, pos))
    {
        pieceThatGives.changeHasBall(false);
        board.getPiece(pos).changeHasBall(true);
        //pieceThatReceive.changeHasBall(true);
    }
}*/

bool Piece::getHasBall()
{
    return hasBall_;
}

void Piece::setColor(Color color)
{
    this->color_ = color;
}

void Piece::changeHasBall(bool hasBall)
{
    this->hasBall_ = hasBall;
}

bool Piece::isReal()
{
    Player player;
    return player.isReal(color_);
}
