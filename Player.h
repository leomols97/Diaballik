/**
 * Project Diaballik
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "Color.h"
#include "Piece.h"
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
            bool hasPass_;

        public:

            Player();
            /**
 * @param color
 */
            Player(Color color_);

            inline bool getHasPass()
            {
                return this->hasPass_;
            }

            inline void setHasPass(bool hasPass)
            {
                this->hasPass_ = hasPass;
            }

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
