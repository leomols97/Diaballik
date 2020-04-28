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

            /**
             * @brief board_ the board is a vector of vector of squares that contains the pieces
             */
            vector<vector<Square>> board_;

            unsigned int boardLength_;

        public:

            /**
             * @brief Board the default board to let the classes that need them use it
             */
            //Board();

            Board(unsigned int boardLength);

            /**
             * @brief Board the contructor that constructs a board belonging a vector of vector
             * @param board_
             */
            //Board(vector<vector<Square>> board_);

            //~Board();

            /**
             * @brief getPiece Gets the piece thats stands on a certain position
             * @param position the position where to find a piece
             * @return the piece found of there's one on it
             */
            Piece getPiece(Position position) const;

            /**
             * @brief getSquare Gets a square at a certain position to find what it contains
             * @param position the position where to look
             * @return the square found
             */
            Square getSquare(Position position) const;

            /**
             * @brief getBoard Gets the vector of vector
             * @return the vector of vector board
             */
            inline vector<vector<Square>> getBoard() const
            {
                return this->board_;
            }

            /**
             * @brief isInside Verifies if a position is inside the board
             * @param position the position to verify
             * @return true if the position is inside and false else
             */
            bool isInside(Position position) const;

            /**
             * @brief isFree Verifies if a position contains a piece or not
             * @param position the position to verify
             * @return true if there's a piece on it and false else
             */
            bool isFree(Position position) const;

            /**
             * @brief isEmpty Verifies if the board is empty or not (for the initialization of the board)
             * @return true if the board is empty and false else
             */
            bool isEmpty();

            /**
             * @brief put Put a piece at a certain position
             * @param piece the piece to put
             * @param position the location where to put the piece
             */
            void put(Piece piece, Position position);

            /**
             * @brief getTakenSquares Gets all the squares taken by a player
             * @param player the player for whom look for the piece
             * @return a vector of position where his pieces stand
             */
            vector<Position> getTakenSquares(Player player);

            /**
             * @brief remove remove a piece at a certain position
             * @param position the position where to remove off a piece
             */
            void remove(Position position);

            /**
             * @brief isMyOwn Verifies if a piece at a position belongs to the current player or not
             * @param position the position where a piece should stand
             * @param color the color of the current player
             * @return true if it the piece belongs to him and false else
             */
            bool isMyOwn(Position position, Color color) const;
    };
}


#endif //_BOARD_H