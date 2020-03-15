#ifndef GAME_H
#define GAME_H

#include <string>

#include "Objects/Ball.h"
#include "Objects/Player.h"
#include "Objects/EnemyPLayer.h"
#include "Controllers/PlayerController.h"
#include "Controllers/BotController.h"
#include "Objects/Line.h"
#include "IGame.h"

class Game : public IGame {
public:
    Game()
        : mBall{  }
        , mPlayer{  }
        , mEnemy{  }
        , mPlayerController {mPlayer, SDL_SCANCODE_W, SDL_SCANCODE_S}
        , mGameWindow {  }
        , mLine {  }
    {
    }

    void mainLoop(SDL_Texture* squareTexture, SDL_Renderer* renderer, EGameType gameType) override;

private:
    void playerColision();
    void boundPlayerColision();
    void botColision();
    void boundBotColision();

    Ball mBall;
    Player mPlayer;
    EnemyPlayer mEnemy;
    PlayerController mPlayerController;
    GameWindow mGameWindow;
    Line mLine;
};

#endif // GAME_H
