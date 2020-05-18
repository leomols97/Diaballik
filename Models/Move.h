/**
 * Project Diaballik
 */


#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Piece.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

using namespace std;
using namespace Diaballik;


namespace Diaballik
{

    class Move
    {

        private:

            /**
             * @brief piece_ the piece we have to move
             */
            Piece &piece_;

            /**
             * @brief start_ the starting position
             */
            Position &start_;

            /**
             * @brief end_ the ending position
             */
            Position &end_;


        public:

            /**
             * @brief Move constructs a move characterised by a piece and 2 positions
             * @param piece_ the piece we have to move
             * @param start_ the starting position
             * @param end_ the ending position
             */
            Move(Piece &piece_, Position &start_, Position &end_);

            /**
             * @brief getPiece
             * @return the piece we have to move
             */
            inline Piece &getPiece() const
            {
                return this->piece_;
            }

            /**
             * @brief getStart
             * @return the starting position
             */
            inline Position &getStart() const
            {
                return this->start_;
            }

            /**
             * @brief getEnd
             * @return the ending position
             */
            inline Position &getEnd() const
            {
                return this->end_;
            }
    };
}
#endif //_MOVE_H
