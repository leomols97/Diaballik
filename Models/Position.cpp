/**
 * Project Diaballik
 * Position implementation
 */


#include "Position.h"

using namespace Diaballik;


/**
 * @param row
 * @param column
 */
Position::Position(int row, int column) :
    row_(row),
    column_(column)
{}

Position Position::whichEndingPosition(Position position, Direction direction) const
{
    switch (direction)
    {
    case Direction::N :
        position.setRow(position.getRow()-1);
        break;
    case Direction::S :
        position.setRow(position.getRow()+1);
        break;
    case Direction::E :
        position.setColumn(position.getColumn()-1);
        break;
    case Direction::O :
        position.setColumn(position.getColumn()+1);
        break;
    case Direction::NE :
        position.setRow(position.getRow()-1);
        position.setColumn(position.getColumn()-1);
        break;
    case Direction::NO :
        position.setRow(position.getRow()-1);
        position.setColumn(position.getColumn()+1);
        break;
    case Direction::SE :
        position.setRow(position.getRow()+1);
        position.setColumn(position.getColumn()-1);
        break;
    case Direction::SO :
        position.setRow(position.getRow()+1);
        position.setColumn(position.getColumn()+1);
        break;
    /*default :
        cout << "Direction inexistante !";
        break;*/
    }
    return position;
}

/**
 * @param dir
 * @return Position
 */
Position Position::next(Position position, Direction direction) const
{
    whichEndingPosition(position, direction);
    position.setRow(position.getRow() + whichEndingPosition(position, direction).getRow());
    position.setColumn(position.getColumn() + whichEndingPosition(position, direction).getColumn());
    Position pos = position;
    return pos;
}
