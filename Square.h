/**
 * Project Diaballik
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#include "Piece.h"

using namespace std;

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
             * @return the piece on the square
             */
            inline Piece getPiece()
            {
                return this->piece_;
            }

            /**
              * @brief put
              * puts a piece on the square by changing it's color to the color of the piece
              * @param piece_ the piece to put on the square
              */
             void put(Piece piece_);

             /**
              * @brief remove
              * removes a piece by changing its "color" to none
              */
             void remove();

             /**
              * @param color
              * @return true if the color given is the same as the color of the piece on the square. false otherwise
              */
              bool isMyOwn(Color color);

              /**
               * @brief isFree
               * @return true if the square has no piece on it
               */
              bool isFree();
    };
}

#endif //_SQUARE_H
