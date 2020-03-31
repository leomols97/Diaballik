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

        /**
             * @brief piece_ the piece inside the square
             */
            Piece piece_;


        public:

            /**
             * @brief Square construts an empty square
             */
            Square();

            /**
             * @brief Square constructs a square with a piece in it
             * @param piece_ the piece inside the square
             */
            Square(Piece piece_);

            /**
             * @brief getPiece
             * @return
             */
            inline Piece getPiece()
            {
                return this->piece_;
            }

            /**
              * @brief put
              * @param piece_
              */
             void put(Piece piece_);

             /**
              * @brief remove
              */
             void remove();

             /**
              * @param color
              */
              bool isMyOwn(Color color);

              /**
               * @brief isFree
               * @return
               */
              bool isFree();
    };
}

#endif //_SQUARE_H
