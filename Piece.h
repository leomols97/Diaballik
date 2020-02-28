/**
 * Project Diaballik
 */


#ifndef _PIECE_H
#define _PIECE_H
#import "Color.h"
#import "Position.h"

using namespace std;
using namespace PositionSpace;

namespace PieceSpace
{

class Piece {

private:
    bool haveBall;
    Position position;
    Color color;

public: 
    
/**
 * @param color
 */
Piece(Color color);
    
bool canPassBall();
    
void passBall();

};
}
#endif //_PIECE_H
