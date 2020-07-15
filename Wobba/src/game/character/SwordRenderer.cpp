#include "SwordRenderer.h"

SwordRenderer::SwordRenderer(CharacterInfo &characterInfo) : SpriteRenderer("assets/sword.png"), characterInfo(characterInfo)
{
}

void SwordRenderer::render()
{
    if (!characterInfo.attacking) {
        return;
    }
    
    if (this->characterInfo.attackDuration >= 300) {
        return;
    }

    SpriteRenderer::render();
}

GVector<int> SwordRenderer::getOffset()
{
    return { this->characterInfo.attackDuration / 100 + 6, 4 };
}
