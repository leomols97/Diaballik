/**
 * Project Diaballik
 */


#include "Position.h"
#include <iostream>

using namespace std;
using namespace PositionSpace;

/**
 * Position implementation
 */


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
    return NULL;
}

/**
 * @return int
 */
int Position::getRow() {
    return 0;
}

/**
 * @return int
 */
int Position::getColumn() {
    return 0;
}

