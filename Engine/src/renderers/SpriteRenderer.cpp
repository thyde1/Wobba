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
    this->render(0, SpriteRenderer::Flip::NONE);
}

void SpriteRenderer::render(const double rotation)
{
    this->render(rotation, Flip::NONE);
}

void SpriteRenderer::render(const Flip flip)
{
    this->render(0, flip);
}

SDL_RendererFlip getSdlFlip(const SpriteRenderer::Flip flip)
{
    switch (flip) {
    case SpriteRenderer::Flip::NONE:
        return SDL_RendererFlip::SDL_FLIP_NONE;
    case SpriteRenderer::Flip::HORIZONTAL:
        return SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
    case SpriteRenderer::Flip::VERTICAL:
        return SDL_RendererFlip::SDL_FLIP_VERTICAL;
    }
}

void SpriteRenderer::render(const double rotation, Flip flip)
{
    if (this->texture == NULL) {
        this->texture = this->gameObject->game->textureManager.getTexture(this->imagePath);
        SDL_QueryTexture(texture, NULL, NULL, &this->w, &this->h);
        this->center = { this->w / 2, this->h / 2 };
    }

    auto cameraPosition = this->gameObject->game->cameraPosition;
    auto offset = this->getOffset();
    this->textureRect = { (int)(this->gameObject->getGlobalPosition().x - cameraPosition.x + offset.x), (int)(this->gameObject->getGlobalPosition().y - cameraPosition.y + offset.y), this->w, this->h };

    SDL_RenderCopyEx(this->sdlRenderer, texture, NULL, &this->textureRect, rotation, &this->center, getSdlFlip(flip));
}

GVector<int> SpriteRenderer::getOffset()
{
    return { 0, 0 };
}
