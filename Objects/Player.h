#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "Objects/Unit.h"
#include "Utils/Settings.h"
#include "Utils/Singleton.h"

#include "GameWindow.h"

class Player : public Unit {
public:
    Player()
    {
        setPositionW(Singleton<Settings>::instance().boardWidth);
        setPositionH(150);
        setPositionX(Singleton<Settings>::instance().boardWidth / 2 + 10);
        setPositionY(Singleton<Settings>::instance().screenHeight / 2 - getPositionH() / 2);
    }
    void renderScore(SDL_Renderer* render) override;
};

#endif // PLAYER_H
