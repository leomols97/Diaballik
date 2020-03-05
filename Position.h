/**
 * Project Diaballik
 */


#ifndef _POSITION_H
#define _POSITION_H
#import "Direction.h"

using namespace DirectionSpace;

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
            Position next(Direction Direction);

            inline int getRow() const
            {
                return this->row;
            }

            inline int getColumn() const
            {
                return this->column;
            }

    };
}

#endif //_POSITION_H
