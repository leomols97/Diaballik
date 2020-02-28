/**
 * Project Diaballik
 */


#ifndef _PIECE_H
#define _PIECE_H
#import "Color.h"
#import "Position.h"

class Piece {
public: 
    
/**
 * @param color
 */
Piece(Color color);
    
bool canPassBall();
    
void passBall();
private: 
    bool haveBall;
    Position position;
    Color color;
};

#endif //_PIECE_H
