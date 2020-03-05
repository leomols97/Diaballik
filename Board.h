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
            vector<vector<Square>> board;

        public:

            Board(vector<vector<Square>> board);

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
            inline Piece getPiece(Position position) const
            {
                if (!board.isInside(position))
                {
                    throw invalid_argument("La position n'est pas dans le plateau de jeu !");
                }
                return board[position.getRow()][position.getColumn()].getPiece();
            }

    };
}

#endif //_BOARD_H
