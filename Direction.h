/**
 * Project Diaballik
 */


#ifndef _DIRECTION_H
#define _DIRECTION_H
#include <iostream>

enum Dir
{
    UP = (-1, 0),
    DOWN = (1, 0),
    RIGHT = (0, 1),
    LEFT = (0, -1)
};

namespace DirectionSpace
{
    class Direction
    {

        private:

            int row;
            int column;

        public:

            Direction(int row, int column);

            int getColumn();

            int getRow();
    };
}

#endif //_DIRECTION_H
