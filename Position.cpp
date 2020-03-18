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
    this->row = &row;
    this->column = &column;
}

Position whichDirection(Position position, Direction direction)
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
        default :
            cout << "Direction inexistante !";
            break;
    }
    return position;
}

/**
 * @param dir
 * @return Position
 */
Position next(Position position, Direction direction)
{
    whichDirection(position, direction);
    position.setRow(position.getRow() + whichDirection(position, direction).getRow());
    position.setColumn(position.getColumn() + whichDirection(position, direction).getColumn());
    return position;
}
