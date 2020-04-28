/**
 * Project Diaballik
 */


#ifndef PIECE_H
#define PIECE_H
#include "Color.h"
#include "Position.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Piece
    {

        private:

            /**
             * @brief color_ the color of the piece
             */
            Color color_;

            /**
             * @brief hasBall_ a boolean to know if the piece contains the ball
             */
            bool hasBall_;

            /**
             * @brief real_ a boolean to know if the square contains a piece
             */
            bool real_;
            
        public:
            
            /**
             * @brief Piece
             * constucts an empty piece
             */
            Piece();

            /**
             * @brief Piece
             * @param color_ the color of the piece constucted
             * constucts a piece characterized by its color
             */
            Piece(Color color_);

            //~Piece();

            /**
             * @brief getColor
             * @return the color of the piece
             */
            inline Color getColor()
            {
                return this->color_;
            }

            /**
             * @brief setColor
             * @param color_ the color we want to set
             * sets the color at a new value
             */
            void setColor(Color color_);

            /**
             * @brief isReal
             * @return true if the piece has the color Black or White. false otherwise
             */
            bool isReal();

            //bool canPassBall(Position pos);

            //void passBall(Piece pieceThatGives, Position pos);

            //void passeList(std::vector<Position> &list) const;

            /**
             * @brief getHasBall
             * @return true if hasBall is true. false otherwise
             */
            bool getHasBall();

            /**
             * @brief changeHasBall
             * @param hasBall a boolean to know if the piece contains the ball
             * changes the value of hasBall
             */
            void changeHasBall(bool hasBall);

            /**
             * @brief getReal
             * @return true if real_ is true. false otherwise
             */
            bool getReal();
    };
}
#endif //_PIECE_H
