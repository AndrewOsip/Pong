#include "Game.h"
#include "GameWindow.h"
#include "Objects/Line.h"
#include "Controllers/PlayerController.h"
#include "Controllers/BotController.h"

namespace {
float calcAngle(float y1, float y2, int height)
{
    float rely = y1 + height / 2 - y2;
    rely /= height / 2.0;
    return rely * 3.142 / 5.0;
}
}

void Game::playerColision()
{
    if (SDL_HasIntersection(&mPlayer.getPos(), &mBall.getBallRectangle())) {
        mBall.setX(mPlayer.getPositionX() + mPlayer.getPositionW());
        mBall.setSpeed(mBall.getSpeed() * Singleton<Settings>::instance().ballAccelerate);

        float angle = calcAngle(mPlayer.getPositionY(), mBall.getY(), mPlayer.getPositionH());
        mBall.setVx(mBall.getSpeed() * cos(angle));
        mBall.setVy(((mBall.getVy() > 0) ? -1 : 1) * mBall.getSpeed() * sin(angle));
    }
}

void Game::boundPlayerColision()
{
    if (mBall.getY() < 0) {
        mBall.setY(0);
        mBall.setVy(mBall.getVy() * -1);
    }

    if (mBall.getX() < 0) {
        mEnemy.increaseScore();
        mBall.setX(mPlayer.getPositionX() + mPlayer.getPositionW());
        mBall.setY(mPlayer.getPositionY() + mPlayer.getPositionH() / 2);
        mBall.setVx(Singleton<Settings>::instance().ballInitialSpeed);
        mBall.setSpeed(Singleton<Settings>::instance().ballInitialSpeed);
    }

    if (mPlayer.getPositionY() < 0) {
        mPlayer.setPositionY(0);
    }

    if (mPlayer.getPositionY() + mPlayer.getPositionH() > Singleton<Settings>::instance().screenHeight) {
        mPlayer.setPositionY(Singleton<Settings>::instance().screenHeight - mPlayer.getPositionH());
    }
}

void Game::botColision()
{
    if (SDL_HasIntersection(&mEnemy.getPos(), &mBall.getBallRectangle())) {
        mBall.setX(mEnemy.getPositionX() - Singleton<Settings>::instance().ballWidth);
        mBall.setSpeed(mBall.getSpeed() * Singleton<Settings>::instance().ballAccelerate);

        float angle = calcAngle(mEnemy.getPositionY(), mBall.getY(), mEnemy.getPositionH());
        mBall.setVx(-1 * mBall.getSpeed() * cos(angle));
        mBall.setVy(((mBall.getVy() > 0) ? -1 : 1) * mBall.getSpeed() * sin(angle));
    }
}

void Game::boundBotColision()
{
    if (mBall.getY() + Singleton<Settings>::instance().ballHeight >= Singleton<Settings>::instance().screenHeight) {
        mBall.setY(Singleton<Settings>::instance().screenHeight - Singleton<Settings>::instance().ballHeight - 1);
        mBall.setVy(mBall.getVy() * -1);
    }

    if (mBall.getX() + Singleton<Settings>::instance().ballWidth >= Singleton<Settings>::instance().screenWidth) {
        mPlayer.increaseScore();
        mBall.setX(mEnemy.getPositionX() - Singleton<Settings>::instance().ballWidth);
        mBall.setY(mEnemy.getPositionY() + mEnemy.getPositionH() / 2);
        mBall.setVx(-1 * Singleton<Settings>::instance().ballInitialSpeed);
        mBall.setSpeed(Singleton<Settings>::instance().ballInitialSpeed);
    }

    if (mEnemy.getPositionY() < 0) {
        mEnemy.setPositionY(0);
    }

    if (mEnemy.getPositionY() + mEnemy.getPositionH() > Singleton<Settings>::instance().screenHeight) {
        mEnemy.setPositionY(Singleton<Settings>::instance().screenHeight - mEnemy.getPositionH());
    }
}

void Game::mainLoop(SDL_Texture* squareTexture, SDL_Renderer* renderer, EGameType gameType)
{
    std::unique_ptr<IPlayerMovement> enemyPositionChanger = nullptr;
    if (gameType == EGameType::BOT) {
        enemyPositionChanger.reset(new BotController(mEnemy, mBall));
    }
    else if (gameType == EGameType::PLAYER) {
        enemyPositionChanger.reset(new PlayerController(mEnemy, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN));
    }

    while (!mGameWindow.isNeedToCloseWindow() && enemyPositionChanger != nullptr) {
        mPlayerController.changePosition();
        enemyPositionChanger->changePosition();

        boundPlayerColision();
        boundBotColision();

        mBall.changeObjectPosition();

        playerColision();
        botColision();

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, squareTexture, nullptr, &mPlayer.getPos());
        SDL_RenderCopy(renderer, squareTexture, nullptr, &mEnemy.getPos());

        mLine.createLine(squareTexture, renderer);
        mBall.createBall(squareTexture, renderer, mBall.getX(), mBall.getY());

        mPlayer.updateScore(renderer);
        mEnemy.updateScore(renderer);

        mPlayer.renderScore(renderer);
        mEnemy.renderScore(renderer);

        mPlayer.destroyTexture();
        mEnemy.destroyTexture();

        SDL_RenderPresent(renderer);
    }
}




