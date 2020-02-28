/**
 * Project Diaballik
 */


#ifndef _POSITION_H
#define _POSITION_H
#import "Direction.h"

namespace PositionSpace
{

class Position {

private:
    int row;
    int column;

public:

/**
 * @param row
 * @param column
 */
Position(int row, int column);

/**
 * @param dir
 */
Position next(Direction dir );

int getRow();

int getColumn();

};
}

#endif //_POSITION_H
