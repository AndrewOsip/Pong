#ifndef IGAMEWINDOW_H
#define IGAMEWINDOW_H

#include <SDL2/SDL.h>

class IGameWindow
{
public:
    virtual ~IGameWindow() = default;
    virtual void Initialise(SDL_Renderer** renderer, SDL_Window** window) = 0;
    virtual bool isNeedToCloseWindow() = 0;
    virtual void Cleanup(SDL_Renderer** renderer, SDL_Window** window) = 0;

};

#endif // IGAMEWINDOW_H
