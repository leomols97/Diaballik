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
            Color color; // La couleur de la pièce
            bool hasBall;
            bool real; // Chaque case du plateau de jeu contient une pièce.
            // Mais ce booléen nous permet de savoir si la case contient une vraie pièce ou non.
            // Cela permet de gérer des objets

        public:

            /**
 * @param color
 */
            Piece();
            Piece(Color color);

            Color getColor();
    };

    /**
* @param color
*/
     bool isReal();

     bool canPassBall();

     void passBall();

     bool getHasBall();

     bool getReal();

     void setColor(Color color);
}
#endif //_PIECE_H
