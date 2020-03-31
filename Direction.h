/**
 * Project Diaballik
 */


#ifndef DIRECTION_H
#define DIRECTION_H
#include <iostream>

using namespace std;

namespace Diaballik
{
    enum class Direction
    {
        UP,
        DOWN,
        RIGHT,
        LEFT
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
