#include "Objects/Ball.h"
#include "Utils/Singleton.h"
#include "Utils/Settings.h"

namespace {
const float INIT_SPEED = 6.0f;
}

Ball::Ball()
    : mSpeed{ INIT_SPEED }
    , mX{ static_cast<float>(Singleton<Settings>::instance().screenWidth / 2) }
    , mY{ static_cast<float>(Singleton<Settings>::instance().screenHeight / 2) }
    , mVx{ (rand() % 2 == 0) ? INIT_SPEED : -1 * INIT_SPEED }
    , mVy{ -0.5f }
{
    mObjectRectangle.w = Singleton<Settings>::instance().ballHeight;
    mObjectRectangle.h = Singleton<Settings>::instance().ballHeight;
}

void Ball::createBall(SDL_Texture* squareTexture, SDL_Renderer* renderer, float x, float y)
{
    if (renderer && squareTexture) {
        renderTexture(squareTexture, renderer, x, y, Singleton<Settings>::instance().ballWidth, Singleton<Settings>::instance().ballHeight);
    }
}

void Ball::changeObjectPosition()
{
    mX += mVx;
    mY += mVy;

    mObjectRectangle.x = static_cast<int>(mX);
    mObjectRectangle.y = static_cast<int>(mY);
}

void Ball::setSpeed(float speed)  { mSpeed = speed; }
void Ball::setX(float value)  { mX = value; }
void Ball::setY(float value)  { mY = value; }
void Ball::setVx(float value)  { mVx = value; }
void Ball::setVy(float value)  { mVy = value; }
float Ball::getSpeed() const  { return mSpeed; }
float Ball::getX() const  { return mX; }
float Ball::getY() const  { return mY; }
float Ball::getVx() const  { return mVx; }
float Ball::getVy() const  { return mVy; }
SDL_Rect& Ball::getBallRectangle() { return mObjectRectangle; }
