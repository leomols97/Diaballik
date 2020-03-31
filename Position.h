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

            int row_;
            int column_;


        public:
            
            Position();

            /**
 * @param row
 * @param column
 */
            Position(int row_, int column_);

            Position next(Position position, Direction direction);

            inline int getRow()
            {
                return this->row_;
            }

            inline int getColumn()
            {
                return this->column_;
            }

            inline void setRow(int row)
            {
                this->row_ = row;
            }

            inline void setColumn(int column)
            {
                this->column_ = column;
            }

            static Position whichEndingPosition(Position position, Direction &direction);
    };
}

#endif //_POSITION_H
