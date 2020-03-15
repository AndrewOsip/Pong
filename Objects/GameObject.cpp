#include "Objects/GameObject.h"

void GameObject::renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h)
{
    SDL_Rect dest{ x, y, w, h };
    if (w == -1 || h == -1) {
        SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    }
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}
