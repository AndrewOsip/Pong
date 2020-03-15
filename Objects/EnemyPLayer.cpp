#include "Objects/EnemyPLayer.h"

void EnemyPlayer::renderScore(SDL_Renderer* render)
{
    if (render) {
        renderTexture(unitScore, render, Singleton<Settings>::instance().screenWidth / 2 + 40, 10);
    }
}
