/**
 * Project Diaballik
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#import "Piece.h"

using namespace std;
using namespace PieceSpace;

class Square {

    private:
        Piece piece;

    public:

        Square(Piece piece);

        bool isFree();

        /**
 * @param color
 */
        bool isMyOwn(Color color);

        Piece getPiece();

        /**
 * @param piece
 */
        void put(Piece piece);

        void remove();

};

#endif //_SQUARE_H
