/**
 * Project Diaballik
 */


#ifndef MOVE_H
#define MOVE_H

#include "Position.h"
#include "Piece.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{


    class Move
    {

        private:

            Piece piece_;
            Position start_;
            Position end_;


        public:
            Move();

            /**
            * @param piece
            * @param start
            * @param end
            */
            Move(Piece piece_, Position start_, Position end_);

            inline Piece getPiece() const
            {
                return this->piece_;
            }

            inline Position getStart() const
            {
                return this->start_;
            }

            inline Position getEnd() const
            {
                return this->end_;
            }
    };
}
#endif //_MOVE_H
