/**
 * Project Diaballik
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#import "Color.h"
#import "Piece.h"
#include "vector"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Player
    {

        private:

            Color color_;
            vector<Piece> pieces_;
            int nbMoves_;

        public:

            Player();
            /**
 * @param color
 */
            Player(Color color_);

            inline Color getColor() const
            {
                return this->color_;
            }

            inline vector<Piece> getPieces() const
            {
                return this->pieces_;
            }

           /**
       * @param nbMoves
       */
            void setNbMoves(int nbMoves);

            bool isReal(Color color_);

            vector<Direction> allDirections();

            void setColor(Color color);
    };
}

#endif //_PLAYER_H
