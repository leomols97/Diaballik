/**
 * Project Diaballik
 */


#ifndef _PIECE_H
#define _PIECE_H
#import "Color.h"
#import "Position.h"

using namespace std;
using namespace Diaballik;

namespace Diaballik
{

    class Piece
    {

        private:

            struct piece
            {
                Color * colorptr; // La couleur de la pièce
                Color color;
                bool hasBall;
                bool real; // Chaque case du plateau de jeu contient une pièce.
                // Mais ce booléen nous permet de savoir si la case contient une vraie pièce ou non.
                // Cela permet de gérer des objets
            }p;


        public:
            
            /**
 * @param color
 */
            Piece();
            Piece(Color* colorptr);


            inline Color  getColor()
            {
                return p.color;
            }
            void setColor(Color color);

            /**
        * @param color
        */
             bool isReal();

             bool canPassBall();

             void passBall();

             bool getHasBall();

             bool getReal();
    };
}
#endif //_PIECE_H
