#include "Objects/Unit.h"

#include "Utils/Log.h"
#include "Utils/Singleton.h"
#include "Utils/FilePath.h"

Unit::Unit()
    : mWidth{ 20 }
    , mWhiteColor{ 255, 255, 255, 255 }
    , mScore{ 0 }
    , mSpeed{ 4 }
{
}

void Unit::increaseScore()
{
    setScore(getScore() + 1);
}

void Unit::updateScore(SDL_Renderer* renderer)
{
    if (renderer) {
        unitScore = renderText(getScore(), Singleton<FilePath>::instance().FONT_TTF,
            mWhiteColor, 40, renderer);
    }
}

SDL_Texture* Unit::renderText(int score,
    const std::string& fontPath,
    const SDL_Color& color,
    int fontSize,
    SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (font == nullptr) {
        Singleton<Log>::instance().printError("Unable to open font");
        return nullptr;
    }

    SDL_Surface* surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), color);
    if (surface == nullptr) {
        TTF_CloseFont(font);
        Singleton<Log>::instance().printError(
            "Unable to render text to a surface");
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        Singleton<Log>::instance().printError(
            "Unable to render surface to texture");
    }

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}

SDL_Rect& Unit::getPos() { return mPos; }
void Unit::setPositionX(int x) { mPos.x = x; }
void Unit::setPositionY(int y) { mPos.y = y; }
void Unit::setPositionW(int w) { mPos.w = w; }
void Unit::setPositionH(int h) { mPos.h = h; }
void Unit::setScore(int score) { mScore = score; }
void Unit::setSpeed(int speed) { mSpeed = speed; }
void Unit::setWidth(int width) { mWidth = width; }
int Unit::getPositionX() const { return mPos.x; }
int Unit::getPositionY() const { return mPos.y; }
int Unit::getPositionW() const { return mPos.w; }
int Unit::getPositionH() const { return mPos.h; }
int Unit::getScore() const { return mScore; }
int Unit::getSpeed() const{ return mSpeed; }
int Unit::getWidth() const { return mWidth; }
void Unit::destroyTexture() { SDL_DestroyTexture(unitScore); }

