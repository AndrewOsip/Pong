#ifndef ILINE_H
#define ILINE_H

#include <SDL2/SDL.h>

class ILine
{
public:
    virtual ~ILine() = default;
    virtual void createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer) = 0;
};

#endif // ILINE_H
