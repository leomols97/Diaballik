/**
 * Project Diaballik
 */


#ifndef _MOVE_H
#define _MOVE_H

#import "Position.h"
#import "Piece.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{


    class Move
    {

        private:

            Piece *piece;
            Position *start;
            Position *end;


        public:

            /**
            * @param piece
            * @param start
            * @param end
            */
            Move(Piece piece, Position start, Position end);

            inline Piece getPiece() const
            {
                return *this->piece;
            }

            inline Position * getStart() const
            {
                return this->start;
            }

            inline Position * getEnd() const
            {
                return this->end;
            }
    };
}
#endif //_MOVE_H
