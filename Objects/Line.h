#ifndef LINE_H
#define LINE_H

#include "Objects/GameObject.h"
#include "Utils/Settings.h"
#include "Utils/Singleton.h"
#include "Objects/ILine.h"

class Line : public GameObject, public ILine {
public:
    void createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer) override;
};

#endif // LINE_H
