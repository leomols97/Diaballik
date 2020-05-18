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
        Destination,
        PassWhite,
        PassBlack
    };
}

#endif //_COLOR_H
