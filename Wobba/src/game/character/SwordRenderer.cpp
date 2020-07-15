#include "SwordRenderer.h"

SwordRenderer::SwordRenderer(CharacterInfo &characterInfo) : SpriteRenderer("assets/sword.png"), characterInfo(characterInfo)
{
}

void SwordRenderer::render()
{
    if (!characterInfo.attacking) {
        lastFrameTime = -1;
        this->attackingTime = 0;
        return;
    }
    
    int ticks = SDL_GetTicks();
    int elapsed = lastFrameTime < 0 ? 0 : ticks - this->lastFrameTime;
    this->attackingTime += elapsed;
    this->lastFrameTime = ticks;

    if (this->attackingTime >= 300) {
        return;
    }

    SpriteRenderer::render();
}

GVector<int> SwordRenderer::getOffset()
{
    return { this->attackingTime / 100 + 6, 4 };
}
