#ifndef BALL_H
#define BALL_H

#include "Objects/GameObject.h"
#include "Objects/IBall.h"

class Ball : public GameObject, public IBall {
public:
    Ball();

    void setSpeed(float speed) override;
    void setX(float value) override;
    void setY(float value) override;
    void setVx(float value) override;
    void setVy(float value) override;
    float getSpeed() const override;
    float getX() const override;
    float getY() const override;
    float getVx() const override;
    float getVy() const override;
    void createBall(SDL_Texture* squareTexture, SDL_Renderer* renderer, float x, float y) override;
    void changeObjectPosition() override;
    SDL_Rect& getBallRectangle() override;

private:
    SDL_Rect mObjectRectangle;
    float mSpeed;
    float mX;
    float mY;
    float mVx;
    float mVy;
};

#endif // BALL_H
