/**
 * Project Diaballik
 */


#ifndef _BOARD_H
#define _BOARD_H
#include "Position.h"
#include "Piece.h"
#include "Square.h"
#include "Player.h"

using namespace std;

namespace Diaballik
{
        
        class Board
        {
                
            private:
                
                vector<vector<Square>> board;
                
            public:
                
                Board();
                Board(vector<vector<Square>> board);

                /**
        * @param position
        */
                 Piece * getPiece(Position position);
                 Square getSquare(Position position);
                 vector<vector<Square>> getBoard();
                
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
        
        /**
* @param position
*/
         void remove(Position position);
    
};
}


#endif //_BOARD_H
