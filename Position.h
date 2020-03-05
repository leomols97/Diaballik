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

            Position();

            /**
 * @param row
 * @param column
 */
            Position(int row, int column);

            inline int getRow() const
            {
                return this->row;
            }

            inline int getColumn() const
            {
                return this->column;
            }
    };

    /**
* @param dir
*/
    static Position next(Direction Direction);
}

#endif //_POSITION_H
