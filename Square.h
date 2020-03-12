/**
 * Project Diaballik
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#import "Piece.h"

using namespace std;

namespace Diaballik
{

    class Square
    {

        private:

            Piece * piece;


        public:

            Square();

            Square(Piece piece);

            inline Piece * getPiece()
            {
                return piece;
            }

            /**
        * @param piece
        */
             void put(Piece piece);

             void remove();

             /**
         * @param color
         */
              bool isMyOwn(Color color);

              bool isFree();
    };
}

#endif //_SQUARE_H
