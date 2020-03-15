project (pong)

cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    	Controllers/BotController.cpp
        Controllers/PlayerController.cpp
        Objects/Ball.cpp
        Objects/EnemyPLayer.cpp
        Objects/GameObject.cpp
        Objects/Line.cpp
        Objects/Player.cpp
        Objects/Unit.cpp
        Utils/Log.cpp
        main.cpp
        Game.cpp
        GameWindow.cpp
)

add_executable(pong ${SOURCES})

include_directories(pong
    PRIVATE
        ${PROJECT_SOURCE_DIR}/
)

find_library(SDL2TTF_LIBRARIES SDL_ttf)

include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

target_link_libraries(pong ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})







