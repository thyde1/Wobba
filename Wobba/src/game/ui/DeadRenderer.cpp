#include "DeadRenderer.h"

void DeadRenderer::render()
{
    SDL_SetRenderDrawColor(this->sdlRenderer, 255, 0, 0, 255);
    SDL_RenderClear(this->sdlRenderer);
}
