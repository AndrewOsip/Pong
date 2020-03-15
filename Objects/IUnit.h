#ifndef IUNIT_H
#define IUNIT_H

#include "SDL2/SDL.h"

class IUnit {
public:
    virtual ~IUnit() = default;
    virtual SDL_Rect& getPos() = 0;
    virtual void setPositionX(int x) = 0;
    virtual void setPositionY(int x) = 0;
    virtual void setPositionW(int w) = 0;
    virtual void setPositionH(int h) = 0;
    virtual void setScore(int score) = 0;
    virtual void setSpeed(int speed) = 0;
    virtual void setWidth(int width) = 0;
    virtual int getPositionX() const = 0;
    virtual int getPositionY() const = 0;
    virtual int getPositionW() const = 0;
    virtual int getPositionH() const = 0;
    virtual int getScore() const = 0;
    virtual int getSpeed() const = 0;
    virtual int getWidth() const = 0;
    virtual void updateScore(SDL_Renderer* renderer) = 0;
    virtual void increaseScore() = 0;
    virtual void destroyTexture() = 0;
    virtual void renderScore(SDL_Renderer* renderer) = 0;
};

#endif // IUNIT_H
