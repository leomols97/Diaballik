/**
 * Project Diaballik
 */


#ifndef _MOVE_H
#define _MOVE_H

#import "Position.h"
#import "Piece.h"

using namespace std;
using namespace PieceSpace;
using namespace PositionSpace;

namespace MoveSpace {


class Move {

private:
    Piece piece;
    Position start;
    Position end;

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

};
}
#endif //_MOVE_H
