/**
 * Project Diaballik
 */


#ifndef _DIRECTION_H
#define _DIRECTION_H
#include <iostream>

using namespace std;

namespace Diaballik
{
    enum class Direction
    {
        UP = (-1, 0),
        DOWN = (1, 0),
        RIGHT = (0, 1),
        LEFT = (0, -1)
    };

    /*const Dir DirVector[] = {UP, DOWN, RIGHT, LEFT};


    class Direction
    {
        private:

            int *row;
            int *column;

        public:

            Direction(int row, int column);

            inline int * getColumn() const
            {
                return this->row;
            }

            inline int * getRow() const
            {
                return this->column;
            }
    };*/
}

#endif //_DIRECTION_H
