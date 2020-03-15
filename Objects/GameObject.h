#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <SDL2/SDL_ttf.h>

class GameObject {
public:
    void renderTexture(SDL_Texture* texture, SDL_Renderer* render, int x, int y, int w = -1, int h = -1);
};

#endif // IGAMEOBJECT_H
