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

namespace PlayerSpace {


    class Player {

        private:
            Color color;
            int nbMoves;
            vector<Piece> pieces;

        public:

            /**
 * @param color
 */
            Player(Color color);

            bool canPass();

            int getNbMoves();

            /**
 * @param nbMoves
 */
            void setNbMoves(int nbMoves);

            Color getColor();

            vector<Piece> getPieces();

    };
}

#endif //_PLAYER_H
