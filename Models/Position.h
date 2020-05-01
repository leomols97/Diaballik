/**
 * Project Diaballik
 */


#ifndef POSITION_H
#define POSITION_H
#include "Direction.h"

using namespace std;
using namespace Diaballik;


namespace Diaballik
{
    class Position
    {

        private:

            /**
             * @brief row_ the row of the board
             */
            int row_;
            /**
             * @brief column_ the column of the board
             */
            int column_;


        public:

            /**
             * @param row
             * @param column
             * constructs a position with a row and a column
             */
            Position(int row_, int column_);

            /**
             * @brief next
             * @param position the starting position
             * @param direction the direction of the move
             * @return the ending position
             */
            Position next(Position position, Direction direction);

            /**
             * @brief getRow
             * @return the row of the position
             */
            inline int getRow()
            {
                return this->row_;
            }

            /**
             * @brief getColumn
             * @return the column of the position
             */
            inline int getColumn()
            {
                return this->column_;
            }

            /**
             * @brief setRow
             * @param row the new row
             * sets the row at a new value
             */
            inline void setRow(int row)
            {
                this->row_ = row;
            }

            /**
             * @brief setColumn
             * @param column the new column
             * sets the column at a new value
             */
            inline void setColumn(int column)
            {
                this->column_ = column;
            }

            /**
             * @brief whichEndingPosition
             * @param position the starting position
             * @param direction the direction we move
             * @return the ending position
             */
            Position whichEndingPosition(Position position, Direction direction) const;
    };
}

#endif //_POSITION_H
