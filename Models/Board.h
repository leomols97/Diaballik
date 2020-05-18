/**
* Project Diaballik
*/


#ifndef BOARD_H
#define BOARD_H
#include "Position.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

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
           vector<vector<Piece>> board_;

           unsigned int boardLength_;

       public:

           Board();

           Board(unsigned int boardLength);

           //~Board();

           /**
            * @brief getPiece Gets the piece thats stands on a certain position
            * @param position the position where to find a piece
            * @return the piece found of there's one on it
            */
           Piece &getPiece(Position position);

           /**
            * @brief getBoard Gets the vector of vector
            * @return the vector of vector board
            */
           inline vector<vector<Piece>> getBoard()
           {
               return this->board_;
           }

           inline unsigned int getBoardLength()
           {
               return boardLength_;
           }

           inline void setBoardLength(unsigned int boardSize)
           {
               this->boardLength_ = boardSize;
           }

           /**
            * @brief isInside Verifies if a position is inside the board
            * @param position the position to verify
            * @return true if the position is inside and false otherwise
            */
           bool isInside(const Position &position);

           /**
            * @brief isFree Verifies if a position contains a piece or not
            * @param position the position to verify
            * @return true if there's no piece on it and false otherwise
            */
           bool isFree(Position position);

           /**
            * @brief isEmpty Verifies if the board is empty or not (for the initialization of the board)
            * @return true if the board is empty and false otherwise
            */
           bool isEmpty();

           /**
            * @brief put Put a piece at a certain position
            * @param color the color of the piece to add
            * @param position the location where to put the piece
            */
           void put(Color &color, Position &position);

           /**
            * @brief getTakenSquares Gets all the squares taken by a player
            * @param player the player for whom look for the piece
            * @return a vector of position where his pieces stand
            */
           vector<Position> getTakenSquares(Player &player);

           /**
            * @brief remove remove a piece at a certain position
            * @param position the position where to remove off a piece
            */
           void remove(Position &position);

           /**
            * @brief isMyOwn Verifies if a piece at a position belongs to the current player or not
            * @param position the position where a piece should stand
            * @param color the color of the current player
            * @return true if it the piece belongs to him and false else
            */
           bool isMyOwn(Position position, Color color);

           void initializeOriginal();

           void initializeVariante();

           void applyPass(Position &positionThatGives, Position &positionThatReceives, Color playerColor);
   };
}


#endif //_BOARD_H
