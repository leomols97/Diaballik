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

/**
 * @param dir
 * @return Position
 */
Position Position::next(Direction direction) {
    Position p(this->row, this->column);
    p.row = p.getRow() + direction.getRow();
    p.column = p.getColumn() + direction.getColumn();
    return p;
}

