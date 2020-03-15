#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "Objects/Ball.h"
#include "Controllers/IPlayerMovement.h"
#include "Objects/Unit.h"

class BotController : public IPlayerMovement {
public:
    BotController(IUnit& bot, IBall& ball)
        : mBotOrSecondPLayer{ bot }
        , mBall{ ball }
    {
    }
    void changePosition() override;

private:
    IUnit& mBotOrSecondPLayer;
    IBall& mBall;
};

#endif // BOTCONTROLLER_H
