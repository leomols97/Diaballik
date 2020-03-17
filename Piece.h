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

<<<<<<< HEAD
            struct piece
            {
                Color * colorptr; // La couleur de la pièce
                Color color;
                bool hasBall;
                bool real; // Chaque case du plateau de jeu contient une pièce.
                // Mais ce booléen nous permet de savoir si la case contient une vraie pièce ou non.
                // Cela permet de gérer des objets
            }p;

=======
            Color color; // La couleur de la pièce
            bool hasBall;
            bool real; // Chaque case du plateau de jeu contient une pièce.
            // Mais ce booléen nous permet de savoir si la case contient une vraie pièce ou non.
            // Cela permet de gérer des objets
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877

            
        public:
            
            /**
 * @param color
 */
            Piece();
<<<<<<< HEAD
            Piece(Color* colorptr);


            inline Color  getColor()
            {
                return p.color;
=======
            Piece(Color *color);

            inline Color getColor()
            {
                return this->color;
>>>>>>> f1cfbaca4fb4ad9cce51408e3d570aae2000e877
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
