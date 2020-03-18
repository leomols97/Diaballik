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
    this->row = row;
    this->column = column;
}

Position Position::whichDirection(Direction &direction)
{
    Position p(this->row, this->column);
    switch (direction)
    {
        case Direction::UP :
            p.setRow(p.getRow()-1);
        break;
        case Direction::DOWN :
            p.setRow(p.getRow()+1);
        break;
        case Direction::LEFT :
            p.setColumn(p.getColumn()-1);
        break;
        case Direction::RIGHT :
            p.setColumn(p.getColumn()+1);
        break;
        default :
            cout << "Direction inexistante !";
            break;
    }
    return p;
}

/**
 * @param dir
 * @return Position
 */
Position Position::next(Direction direction)
{
    Position p(this->row, this->column);
    whichDirection(direction);
    p.row = p.getRow() + whichDirection(direction).getRow();
    p.column = p.getColumn() + whichDirection(direction).getColumn();
    //p.setRow(p.getRow() + dir.getRow());
    //p.setColumn(p.getColumn() + dir.getColumn());
    return p;
}
