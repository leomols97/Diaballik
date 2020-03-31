/**
 * Project Diaballik
 */


#include "Position.h"
#include <iostream>

using namespace std;
using namespace Diaballik;

/**
 * Position implementation
 */


/**
 * Default constructor needed by the constructor of Game
 * @brief Position
 */
Position::Position() {}

/**
 * @param row
 * @param column
 */
Position::Position(int row, int column)
{
    this->row_ = row;
    this->column_ = column;
}

Position Position::whichEndingPosition(Position position, Direction direction)
{
    switch (direction)
    {
        case Direction::UP :
            position.setRow(position.getRow()-1);
            break;
        case Direction::DOWN :
            position.setRow(position.getRow()+1);
            break;
        case Direction::LEFT :
            position.setColumn(position.getColumn()-1);
            break;
        case Direction::RIGHT :
            position.setColumn(position.getColumn()+1);
            break;
    }
    return position;
}

/**
 * @param dir
 * @return Position
 */
Position Position::next(Position position, Direction direction)
{
    whichEndingPosition(position, direction);
    position.setRow(position.getRow() + whichEndingPosition(position, direction).getRow());
    position.setColumn(position.getColumn() + whichEndingPosition(position, direction).getColumn());
    Position pos = position;
    return pos;
}
