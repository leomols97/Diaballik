#ifndef EVENTPASSBALL_H
#define EVENTPASSBALL_H

#include <QObject>
#include <QWidget>
#include "Models/Game.h"

class EventPassBall : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief game_ the game in which we play
     */
    Game game_;

public:
    /**
     * @brief EventPassBall constructs an event to pass the ball
     * @param game_ the game in which we play
     */
    EventPassBall(Game &game_);
};

#endif // EVENTPASSBALL_H
