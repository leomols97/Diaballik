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
            Piece piece;

        public:

            Square(Piece piece);

            inline Piece getPiece() const
            {
                return this->piece;
            }
    };

    /**
* @param piece
*/
    static void put(Piece piece);

    static void remove();

    static bool isFree();

    /**
* @param color
*/
    static bool isMyOwn(Color color);
}

#endif //_SQUARE_H
