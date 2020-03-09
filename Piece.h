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
            Piece(Color color);

            Color getColor();
    };

    /**
* @param color
*/
    static bool isReal();

    static bool canPassBall();

    static void passBall();

    static bool getHasBall();

    static bool getReal();

    static void setColor(Color color);
}
#endif //_PIECE_H
