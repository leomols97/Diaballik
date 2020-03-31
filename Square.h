/**
 * Project Diaballik
 */


#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
#include "vector"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Square
    {

        private:

            Piece piece_;


        public:

            Square();

            Square(Piece piece_);

            inline Piece getPiece()
            {
                return this->piece_;
            }

            /**
        * @param piece
        */
             void put(Piece piece_);

             void remove();

             /**
         * @param color
         */
              bool isMyOwn(Color color);

              bool isFree();
    };
}

#endif //_SQUARE_H
