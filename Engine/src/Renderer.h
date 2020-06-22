#pragma once
#include "GameObject.h"
#include "Component.h"
#include "SDL.h"

class Renderer : public Component {
public:
    virtual ~Renderer();
    virtual void render();
    void setSdlRenderer(SDL_Renderer *sdlRenderer);
protected:
    SDL_Renderer *sdlRenderer;
};
