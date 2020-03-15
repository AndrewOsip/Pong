#include "Objects/Line.h"

void Line::createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer)
{
    if (renderer && squareTexture) {
        renderTexture(squareTexture, renderer,
            Singleton<Settings>::instance().screenWidth / 2 - Singleton<Settings>::instance().centerWidth / 2, 0,
            Singleton<Settings>::instance().centerWidth, Singleton<Settings>::instance().screenHeight);
    }
}
