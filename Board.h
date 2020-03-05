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

namespace BoardSpace {

    
    class Board {
        private:
            vector<vector<Square>> squares;
        public:

            Board(vector<vector<Square>> squares);

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
            vector<Position> getTakenSquare(Player player);

            vector<vector<Square>> getSquares();

            /**
     * @param position
     */
            void remove(Position position);

            /**
     * @param position
     */
            Piece getPiece(Position position);

    };
}

#endif //_BOARD_H
