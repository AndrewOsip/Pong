#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "IGameWindow.h"

class GameWindow : public IGameWindow {
public:
    void Initialise(SDL_Renderer** renderer, SDL_Window** window) override;
    bool isNeedToCloseWindow() override;
    void Cleanup(SDL_Renderer** renderer, SDL_Window** window) override;

private:
    SDL_Event mEvent;
};

#endif // GAMEWINDOW_H
