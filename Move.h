/**
 * Project Diaballik
 */


#ifndef _MOVE_H
#define _MOVE_H

#import "Position.h"
#import "Piece.h"

class Move {
public: 
    
/**
 * @param piece
 * @param start
 * @param end
 */
Move(Piece piece, Position start, Position end);
    
Piece getPiece();
    
Position getStart();
    
Position getEnd();
private: 
    Piece piece;
    Position start;
    Position end;
};

#endif //_MOVE_H
