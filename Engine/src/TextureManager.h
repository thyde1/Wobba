#pragma once

#include <map>
#include "SDL.h"

class TextureManager
{
public:
    TextureManager();
    TextureManager(SDL_Renderer *sdlRenderer);
    SDL_Texture* getTexture(const char *imageName);
private:
    SDL_Renderer *sdlRenderer;
    std::map<const char*, SDL_Texture*> textures;
};
