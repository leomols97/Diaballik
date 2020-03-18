/**
 * Project Diaballik
 */


#ifndef _POSITION_H
#define _POSITION_H
#import "Direction.h"

using namespace Diaballik;

namespace Diaballik
{

    class Position
    {

        private:

            int row;
            int column;


        public:
            
            Position();

            /**
 * @param row
 * @param column
 */
            Position(int row, int column);

            Position next(Direction direction);

            inline int getRow()
            {
                return this->row;
            }

            inline int getColumn()
            {
                return this->column;
            }

            inline void setRow(int row)
            {
                this->row = row;
            }

            inline void setColumn(int column)
            {
                this->column = column;
            }



    };
}

#endif //_POSITION_H
