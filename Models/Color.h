/**
 * Project Diaballik
 */


#ifndef COLOR_H
#define COLOR_H

#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace Diaballik
{
    enum Color
    {
        None,
        White,
        WhiteSelected,
        WhiteWithBall,
        WhiteWithBallSelected,
        Black,
        BlackSelected,
        BlackWithBall,
        BlackWithBallSelected,
        //Les endroits où la piece séelctionnée peut aller
        Destination,
        // Les pièces qui peuvent recevoir la balle lors d'une passe
        PassWhite,
        PassBlack
    };
}

#endif //_COLOR_H
