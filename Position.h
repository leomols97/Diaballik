/**
 * Project Diaballik
 */


#ifndef _POSITION_H
#define _POSITION_H
#import "Direction.h"

class Position {
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
private:
    int row;
    int column;
};

#endif //_POSITION_H
