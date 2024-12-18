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
Position::Position(unsigned int row, unsigned int column) :
    row_(row),
    column_(column)
{}

Position Position::whichEndingPosition(Position &position, Direction &direction)
{
    switch (direction)
    {
    case Direction::N :
        position.setRow(-1);
        position.setColumn(0);
        break;
    case Direction::S :
        position.setRow(1);
        position.setColumn(0);
        break;
    case Direction::E :
        position.setRow(0);
        position.setColumn(-1);
        break;
    case Direction::O :
        position.setRow(0);
        position.setColumn(1);
        break;
    case Direction::NE :
        position.setRow(-1);
        position.setColumn(-1);
        break;
    case Direction::NO :
        position.setRow(-1);
        position.setColumn(1);
        break;
    case Direction::SE :
        position.setRow(1);
        position.setColumn(-1);
        break;
    case Direction::SO :
        position.setRow(1);
        position.setColumn(1);
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
Position &Position::next(Position position, Direction direction)
{
    whichEndingPosition(position, direction);
    position.setRow(position.getRow() + whichEndingPosition(position, direction).getRow());
    position.setColumn(position.getColumn() + whichEndingPosition(position, direction).getColumn());
    Position pos = position;
    return pos;
}
