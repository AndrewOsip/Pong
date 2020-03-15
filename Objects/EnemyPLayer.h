#ifndef BOT_H
#define BOT_H

#include "Objects/Unit.h"

#include "Utils/Log.h"
#include "Utils/Singleton.h"
#include "Utils/Settings.h"

class EnemyPlayer : public Unit {
public:
    EnemyPlayer()
    {
        setPositionW(Singleton<Settings>::instance().boardWidth);
        setPositionH(150);
        setPositionX(Singleton<Settings>::instance().screenWidth - getPositionW() - 10 - getPositionW() / 2);
        setPositionY(Singleton<Settings>::instance().screenHeight / 2 - getPositionH() / 2);
    }
    virtual ~EnemyPlayer() override = default;
    void renderScore(SDL_Renderer* render) override;
};

#endif // BOT_H
