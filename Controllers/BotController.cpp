#include "Controllers/BotController.h"
#include "Utils/Singleton.h"
#include "Utils/Settings.h"

void BotController::changePosition()
{
    if (mBall.getY() < mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH() / 2) {
        mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() - mBotOrSecondPLayer.getSpeed());
    }
    if (mBall.getY() > mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH() / 2) {
        mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getSpeed());
    }

    if (mBall.getVx() > Singleton<Settings>::instance().ballMaxSpeed) {
        mBall.setVx(Singleton<Settings>::instance().ballMaxSpeed);
    }
    if (mBall.getVy() > Singleton<Settings>::instance().ballMaxSpeed) {
        mBall.setVy(Singleton<Settings>::instance().ballMaxSpeed);
    }
}
