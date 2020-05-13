#ifndef EVENTPASSBALL_H
#define EVENTPASSBALL_H

#include <QObject>
#include <QWidget>
#include "Game.h"

class EventPassBall : public QWidget
{
    Q_OBJECT
private:
    Game game_;

public:
    EventPassBall(Game game_);
};

#endif // EVENTPASSBALL_H
