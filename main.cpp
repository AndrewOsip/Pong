#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Objects/EGameType.h"
#include "Game.h"
#include "Utils/FilePath.h"

int main()
{
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    SDL_Texture* squareTexture;

    //__________________________MENU___________________________________________________________
    std::cout << "Main menu\n"
              << "Play with Bot(press b)\n"
              << "Play with another Player(press p)" << std::endl;

    std::string modeSwitcher;
    getline(std::cin, modeSwitcher);
    //__________________________END_MENU______________________________________________________________

    EGameType gameType{ EGameType::UNDEFINED };
    if (modeSwitcher == "b") {
        gameType = EGameType::BOT;
    }
    else if (modeSwitcher == "p") {
        gameType = EGameType::PLAYER;
    }

    GameWindow gameWindow;
    gameWindow.Initialise(&renderer, &window);

    squareTexture = IMG_LoadTexture(renderer, Singleton<FilePath>::instance().BOARD_IMG.c_str());
    SDL_QueryTexture(squareTexture, nullptr, nullptr, &Singleton<Settings>::instance().boardWidth,
        &Singleton<Settings>::instance().boardHeight);
    SDL_RenderPresent(renderer);

    Game game;
    game.mainLoop(squareTexture, renderer, gameType);

    SDL_DestroyTexture(squareTexture);
    gameWindow.Cleanup(&renderer, &window);

    return 0;
}
