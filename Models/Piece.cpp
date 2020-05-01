/**
 * Project Diaballik
 */


#include "Piece.h"
#include "Player.h"

using namespace Diaballik;


/**
 * @param color
 */
Piece::Piece(Color color) :
    color_(color)
    //hasBall_(false)
{
        //this->color_ = color;
        //this->real_ = true;
        //this->hasBall_ = false;
}

/**
 * @return boolean
 */
bool Piece::canPassBall(Position pos)
{
    /*Player player(color_);
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
            for (unsigned int i = 0; i < 7; i++)
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
    return canPass;*/
}

/*void Piece::passBall(Piece pieceThatGives, Position pos)
{
    if(pieceThatGives.canPassBall(pos))
    {
        pieceThatGives.changeHasBall(false);
        Board().getPiece(pos).changeHasBall(true);
        //pieceThatReceive.changeHasBall(true);
    }
}*/

/*void Piece::passeList(vector<Position> &list) const
{
    for (int dirInt = 1; dirInt <= 8; dirInt++) {
        bool ok = true;
        const Direction dir = static_cast<Direction>(dirInt);
        Position posNext = Game().getSelected().next(Game().getSelected(), dir);

        while (ok)
        {
            ok = Board().isInside(posNext) && !Board().isMyOwn(posNext, Game().getOpponent().getColor());

            if (ok && Board().isMyOwn(posNext, Game().getCurrent().getColor()))
            {
                list.push_back(Position(posNext.getRow(), posNext.getColumn()));
                posNext = posNext.next(posNext, dir);
                ok = Board().isInside(posNext) && !Board().isMyOwn(posNext, Game().getOpponent().getColor());
            }

            if (ok && Board().isFree(posNext))
            {
                posNext = posNext.next(posNext, dir);
            }
        }
    }
}*/

/*bool Piece::canPassBall(Position pos)
{
    vector<Position> listOfPositions;
    passeList(listOfPositions);
    bool found = false;

    for (size_t i {0}; i < (listOfPositions.size()) && !found; i++)
    {
        if (pos == listOfPositions.at(i))
        {
            found = true;
        }
    }
    return found && Player().getHasPass();
}*/

/*bool Piece::getHasBall()
{
    return hasBall_;
}*/

void Piece::setColor(Color color)
{
    this->color_ = color;
}

/*void Piece::changeHasBall(Color color)
{
    if (color != WhiteWithBall || color != BlackWithBall)
    {

    }
}*/

/*bool Piece::isReal()
{
    return this->
}*/
