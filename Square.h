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


        public:

            Piece piece;

            Square();

            Square(Piece piece);

            inline Piece getPiece() const
            {
                return this->piece;
            }
    };

    /**
* @param piece
*/
     void put(Piece piece);

     void remove();

     bool isFree();

    /**
* @param color
*/
     bool isMyOwn(Color color);
}

#endif //_SQUARE_H
