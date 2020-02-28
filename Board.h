/**
 * Project Diaballik
 */


#ifndef _BOARD_H
#define _BOARD_H
#import "Position.h"
#import "Piece.h"
#import "Square.h"
#import "Player.h"

class Board {
public:

Board();

/**
 * @param position
 */
bool isInside(Position position);

/**
 * @param position
 */
bool isFree(Position position);

/**
 * @param piece
 * @param position
 */
void put(Piece piece, Position position);

/**
 * @param player
 */
List<Position> getTakenSquare(Player player);

Square [][] getSquares();

/**
 * @param position
 */
void remove(Position position);

/**
 * @param position
 */
Piece getPiece(Position position);
private:
    Square [][] squares;
};

#endif //_BOARD_H
