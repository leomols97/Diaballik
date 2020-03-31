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

            Color color_; // La couleur de la pièce
            bool hasBall_;
            bool real_; // Chaque case du plateau de jeu contient une pièce.
            // Mais ce booléen nous permet de savoir si la case contient une vraie pièce ou non.
            // Cela permet de gérer des objets

            
        public:
            
            /**
 * @param color
 */
            Piece();

            Piece(Color color_);

            inline Color getColor()
            {
                return this->color_;
            }

            void setColor(Color color_);

            /**
        * @param color
        */
            bool isReal();

            bool canPassBall(Position pos);

            void passBall(Piece pieceThatGives, Position pos);

            bool getHasBall();

            void changeHasBall(bool hasBall);

            bool getReal();
    };
}
#endif //_PIECE_H
