/**
 * Project Diaballik
 */


#ifndef BOARD_H
#define BOARD_H
#include "Position.h"
#include "Square.h"
#include "Player.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Board
    {

        private:

            vector<vector<Square>> board_;

        public:

            Board();
            Board(vector<vector<Square>> board_);

            /**
        * @param position
        */
            Piece getPiece(Position position);

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

            bool isEmpty();

            /**
* @param piece
* @param position
*/
            void put(Piece piece, Position position);

            /**
* @param player
*/
            vector<Position> getTakenSquares(Player player);

            /**
* @param position
*/
            void remove(Position position);

            bool isMyOwn(Position position, Color color);

            void initialize();
    };
}


#endif //_BOARD_H
