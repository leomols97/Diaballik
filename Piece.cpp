/**
 * Project Diaballik
 */

#include "Piece.h"
#include "Player.h"
#include "Board.h"
#include "Color.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Piece implementation
 */

Piece::Piece()
{
    this->real = false;
}

/**
 * @param color
 */
Piece::Piece(Color color)
{

    this->color = &color;
    this->real = true;
    this->hasBall = false;
}

/**
 * @return boolean
 */
bool Piece::canPassBall(Position pos) {
    bool canPass = false;
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
            if(Board().isInside(posD) && Board().isInside(posG) &&
                    Board().isInside(posB) && Board().isInside(posH) &&
                    Board().isInside(posHD) && Board().isInside(posHG) &&
                    Board().isInside(posBD) && Board().isInside(posBG))
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
                if(Board().isMyOwn(posD, getColor()) || Board().isMyOwn(posG, getColor()) ||
                        Board().isMyOwn(posB, getColor()) || Board().isMyOwn(posH, getColor()) ||
                        Board().isMyOwn(posHD, getColor()) || Board().isMyOwn(posHG, getColor()) ||
                        Board().isMyOwn(posBD, getColor()) || Board().isMyOwn(posBG, getColor()))
                {
                    canPass = true;
                }
            }
        }
    }
    return canPass;
}

/**
 * @return void
 */

void Piece::passBall(Piece *piece, Position pos)
{
    if(canPassBall(pos))
    {
        changeHasBall(piece);
    }
}

bool getHasBall()
{
    return true;
}

void Piece::setColor(Color *color)
{
    this->color = color;
}

bool changeHasBall(Piece *piece)
{
    if (piece->getHasBall() ==  true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Piece::isReal(){
    Player player;
    return player.isReal(color);
}
