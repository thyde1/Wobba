#include "Renderer.h"

Renderer::~Renderer()
{
}

void Renderer::render()
{
}

void Renderer::setSdlRenderer(SDL_Renderer *sdlRenderer)
{
    this->sdlRenderer = sdlRenderer;
}
