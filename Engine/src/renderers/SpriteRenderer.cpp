#include "SDL.h"
#include "SpriteRenderer.h"
#include "../Game.h"

SpriteRenderer::SpriteRenderer(const char *imagePath) : imagePath(imagePath), w(0), h(0), texture(NULL), textureRect{ NULL }
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::render()
{
    this->render(0);
}

void SpriteRenderer::render(const double rotation)
{
    if (this->texture == NULL) {
        this->texture = this->gameObject->game->textureManager.getTexture(this->imagePath);
        SDL_QueryTexture(texture, NULL, NULL, &this->w, &this->h);
        this->center = { this->w / 2, this->h / 2 };
    }

    auto cameraPosition = this->gameObject->game->cameraPosition;
    auto offset = this->getOffset();
    this->textureRect = { (int)(this->gameObject->getGlobalPosition().x - cameraPosition.x + offset.x), (int)(this->gameObject->getGlobalPosition().y - cameraPosition.y + offset.y), this->w, this->h };
    SDL_RenderCopyEx(this->sdlRenderer, texture, NULL, &this->textureRect, rotation, &this->center, SDL_RendererFlip::SDL_FLIP_NONE);
}

GVector<int> SpriteRenderer::getOffset()
{
    return { 0, 0 };
}
