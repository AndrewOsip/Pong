#ifndef PROPERTIES_H
#define PROPERTIES_H

class Settings {
public:
    //screen properties
    const int screenWidth = 640;
    const int screenHeight = 480;
    const int centerWidth = 5;

    //board properies
    int boardWidth;
    int boardHeight;

    // ball properties
    const float ballMaxSpeed = 8.0f;
    const float ballAccelerate = 1.05f;
    const float ballInitialSpeed = 6.0f;
    const int ballWidth = 10;
    const int ballHeight = 10;
};

#endif // PROPERTIES_H
