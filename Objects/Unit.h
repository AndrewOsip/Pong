#ifndef IPLAYER_H
#define IPLAYER_H

#include "Objects/GameObject.h"
#include "Objects/IUnit.h"

#include <string>

class Unit : public GameObject, public IUnit {
public:
    Unit();

    SDL_Rect& getPos() override;
    void setPositionX(int x) override;
    void setPositionY(int y) override;
    void setPositionW(int w) override;
    void setPositionH(int h) override;
    void setScore(int score) override;
    void setSpeed(int speed) override;
    void setWidth(int width) override;
    int getPositionX() const override;
    int getPositionY() const override;
    int getPositionW() const override;
    int getPositionH() const override;
    int getScore() const override;
    int getSpeed() const override;
    int getWidth() const override;
    void updateScore(SDL_Renderer* renderer) override;
    void destroyTexture() override;
    void increaseScore() override;

protected:
    SDL_Texture* unitScore;

private:
    SDL_Texture* renderText(int score, const std::string& fontPath, const SDL_Color& color, int fontSize, SDL_Renderer* render);
    int mWidth;
    SDL_Color mWhiteColor;
    SDL_Rect mPos;
    int mScore;
    int mSpeed;
};

#endif // IPLAYER_H
