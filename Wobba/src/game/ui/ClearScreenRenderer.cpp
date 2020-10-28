#include "ClearScreenRenderer.h"

ClearScreenRenderer::ClearScreenRenderer(SDL_Color color) : color(color)
{
}

void ClearScreenRenderer::render()
{
    SDL_SetRenderDrawColor(this->sdlRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(this->sdlRenderer);
}
