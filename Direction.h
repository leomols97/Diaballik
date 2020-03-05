/**
 * Project Diaballik
 */


#ifndef _DIRECTION_H
#define _DIRECTION_H
#include <iostream>

namespace DirectionSpace
{

    //struct D
    //{
    enum Direction {
        UP = (-1, 0),
        DOWN = (1, 0),
        RIGHT = (0, 1),
        LEFT = (0, -1)

        private:
        int row;
        int column;

        public:

        Direction(int row, int column);

        int getRow();
        int getColumn();
    };
}

#endif //_DIRECTION_H
