#ifndef IGAME_H
#define IGAME_H

#include "GameWindow.h"
#include "Objects/EGameType.h"

class IGame
{
public:
    virtual ~IGame() = default;
    virtual void mainLoop(SDL_Texture* squareTexture, SDL_Renderer* renderer, EGameType gameType) = 0;
};

#endif // IGAME_H
