#pragma once

#include "SDL.h"
#include "Engine.h"

class ClearScreenRenderer : public Renderer {
public:
    ClearScreenRenderer(SDL_Color color);
    void render();
private:
    SDL_Color color;
};
