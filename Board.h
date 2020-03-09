/**
 * Project Diaballik
 */


#ifndef _BOARD_H
#define _BOARD_H
#import "Position.h"
#import "Piece.h"
#import "Square.h"
#import "Player.h"

using namespace std;
using namespace PieceSpace;
using namespace PlayerSpace;
using namespace PositionSpace;
using namespace SquareSpace;

namespace BoardSpace
{
    
    class Board
    {

        private:
            vector<vector<Square>> board;

        public:

            Board();
            Board(vector<vector<Square>> board);
    };


    /**
* @param position
*/
    static bool isInside(Position position);

    /**
* @param position
*/
    static bool isFree(Position position);

    /**
* @param piece
* @param position
*/
    static void put(Piece piece, Position position);

    static vector<vector<Square>> getBoard();

    /**
* @param player
*/
    static vector<Position> getTakenSquare(Player player);

    /**
* @param position
*/
    static void remove(Position position);

    /**
* @param position
*/
    static Piece getPiece(Position position);
}

#endif //_BOARD_H
