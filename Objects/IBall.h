#ifndef IBALL_H
#define IBALL_H

#include <SDL2/SDL.h>

class IBall {
public:
    virtual ~IBall() = default;
    virtual SDL_Rect& getBallRectangle() = 0;
    virtual void setX(float value) = 0;
    virtual void setY(float value) = 0;
    virtual void setVx(float value) = 0;
    virtual void setVy(float value) = 0;
    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual float getVx() const = 0;
    virtual float getVy() const = 0;
    virtual void setSpeed(float speed) = 0;
    virtual float getSpeed() const = 0;
    virtual void changeObjectPosition() = 0;
    virtual void createBall(SDL_Texture* squareTexture, SDL_Renderer* renderer, float x, float y) = 0;

};

#endif // IBALL_H
