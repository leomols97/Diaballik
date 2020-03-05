/**
 * Project Diaballik
 */


#ifndef _DIRECTION_H
#define _DIRECTION_H
#include <iostream>
using namespace std;


enum Dir {
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

            inline int getRow() const
            {
                return row;
            }

            inline int getColumn() const
            {
                return column;
            }
    };
}

#endif //_DIRECTION_H
