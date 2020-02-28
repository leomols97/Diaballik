/**
 * Project Diaballik
 */


#ifndef _SQUARE_H
#define _SQUARE_H

#import "Piece.h"

class Square {
public: 
    
Square();
    
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
private: 
    Piece piece;
};

#endif //_SQUARE_H
