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

    SpriteRenderer::render(this->characterInfo.lastMovementDirection == Direction::LEFT ? Flip::HORIZONTAL : Flip::NONE);
}

GVector<int> SwordRenderer::getOffset()
{
    if (this->characterInfo.lastMovementDirection == Direction::LEFT) {
        return { -this->characterInfo.attackDuration / 100 - 2, 4 };
    }
    else {
        return { this->characterInfo.attackDuration / 100 + 6, 4 };
    }
}
