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
<<<<<<< HEAD
Position next(Direction direction)
{
    return NULL;
=======
Position next(Direction direction) {
    return null;
>>>>>>> 464b33679382e25399a8e076f2ccf3baa5df2c5a
}

/**
 * @return int
 */
int getRow() {
    return this.row;
}

/**
 * @return int
 */
int getColumn() {
    return this.column;
}

