#include "TextureManager.h"
#include "SDL_image.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
    this->sdlRenderer = nullptr;
}

TextureManager::TextureManager(SDL_Renderer *sdlRenderer)
{
    this->sdlRenderer = sdlRenderer;
}

SDL_Texture* TextureManager::getTexture(const char *imagePath)
{
    if (this->textures.count(imagePath) == 0) {
        SDL_Surface *tempSurface = IMG_Load(imagePath);
        auto texture = SDL_CreateTextureFromSurface(this->sdlRenderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        this->textures[imagePath] = texture;
        return texture;
    }

    return this->textures[imagePath];
}
