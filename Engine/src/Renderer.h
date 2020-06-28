#pragma once

#include "SDL.h"
#include "Component.h"

class Renderer : public Component {
public:
    virtual ~Renderer();
    virtual void render();
    void setSdlRenderer(SDL_Renderer *sdlRenderer);
protected:
    SDL_Renderer *sdlRenderer = nullptr;
};
