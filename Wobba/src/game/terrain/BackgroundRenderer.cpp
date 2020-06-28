#include "BackgroundRenderer.h"

void BackgroundRenderer::render()
{
    SDL_SetRenderDrawColor(this->sdlRenderer, 64, 64, 64, 255);
    SDL_RenderClear(this->sdlRenderer);
}
