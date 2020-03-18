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

            Color *color;
            vector<Piece> pieces;
            int nbMoves;

        public:

            Player();
            /**
 * @param color
 */
            Player(Color color);

            inline Color* getColor() const
            {
                return color;
            }

            inline vector<Piece> getPieces() const
            {
                return this->pieces;
            }
            
            int getNbMoves();

            bool canPass();

           /**
       * @param nbMoves
       */
            void setNbMoves(int nbMoves);

            bool isReal(Color color);
    };
}

#endif //_PLAYER_H
