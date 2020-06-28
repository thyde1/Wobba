#include "AnimatedSpriteRenderer.h"
#include "../Game.h"

AnimatedSpriteRenderer::AnimatedSpriteRenderer(const char *imagePath, Size frameSize, Size destSize, int frameCount)
    : imagePath(imagePath), frameSize{ frameSize }, destSize(destSize), frameCount(frameCount), texture(NULL), textureRect{ NULL }
{
}

AnimatedSpriteRenderer::AnimatedSpriteRenderer(const char *imagePath, Size frameSize, Size destSize) : AnimatedSpriteRenderer(imagePath, frameSize, destSize, 0)
{
}

void AnimatedSpriteRenderer::render()
{
    if (this->texture == NULL) {
        this->texture = this->gameObject->game->textureManager.getTexture(this->imagePath);
        SDL_QueryTexture(texture, NULL, NULL, &this->w, &this->h);
        this->center = { this->w / 2, this->h / 2 };
    }

    auto ticks = SDL_GetTicks();
    this->elapsed += ticks - prevFrame;
    auto animation = this->getAnimation();
    auto currentFrame = (this->elapsed / 100) % animation.frameCount + animation.startFrame;
    auto cameraPosition = this->gameObject->game->cameraPosition;

    SDL_Rect srcRect = { currentFrame * this->frameSize.w, 0, this->frameSize.w, this->frameSize.h };
    SDL_Rect destRect = { (int)(this->gameObject->globalPosition.x - cameraPosition.x), (int)(this->gameObject->globalPosition.y - cameraPosition.y), this->destSize.w, this->destSize.h };
    SDL_RenderCopyEx(this->sdlRenderer, texture, &srcRect, &destRect, NULL, &this->center, animation.flippedHorizontal ? SDL_RendererFlip::SDL_FLIP_HORIZONTAL : SDL_RendererFlip::SDL_FLIP_NONE);
    this->prevFrame = ticks;
}

Animation AnimatedSpriteRenderer::getAnimation()
{
    return Animation{0, this->frameCount, false};
}
