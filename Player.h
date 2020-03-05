/**
 * Project Diaballik
 */


#ifndef _PLAYER_H
#define _PLAYER_H

#import "Color.h"
#import "Piece.h"
#include "vector"

using namespace std;
using namespace PieceSpace;

namespace PlayerSpace
{


    class Player
    {

        private:
            Color color;
            int nbMoves;
            vector<Piece> pieces;

        public:

            Player();
            /**
 * @param color
 */
            Player(Color color);

            inline Color getColor() const
            {
                return color;
            }

            inline vector<Piece> getPieces() const
            {
                return pieces;
            }

    };

    static bool canPass();

    static int getNbMoves();

    /**
* @param nbMoves
*/
    static void setNbMoves(int nbMoves);

    static bool isReal();
}

#endif //_PLAYER_H
