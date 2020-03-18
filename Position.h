/**
 * Project Diaballik
 */


#ifndef _POSITION_H
#define _POSITION_H
#include "Direction.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Position
    {

        private:

            int *row;
            int *column;


        public:
            
            Position();

            /**
 * @param row
 * @param column
 */
            Position(int *row, int *column);

            inline int getRow()
            {
                return *this->row;
            }

            inline int getColumn()
            {
                return *this->column;
            }

            inline void setRow(int row)
            {
                this->row = &row;
            }

            inline void setColumn(int column)
            {
                this->column = &column;
            }

            Position whichDirection(Direction &direction);

            /**
        * @param dir
        */
            Position next(Direction direction);
    };
}

#endif //_POSITION_H
