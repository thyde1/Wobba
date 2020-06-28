#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(CharacterInfo *characterInfo) :
    AnimatedSpriteRenderer(
        "assets/character2.png",
        { 8, 8 },
        { 80, 80 }),
    characterInfo(characterInfo)
{
}

Animation CharacterRenderer::getAnimation()
{
    if (!this->characterInfo->isGrounded) {
        return jumping;
    }
    switch (this->characterInfo->direction) {
    case Direction::LEFT:
        return walkingLeft;
    case Direction::RIGHT:
        return walkingRight;
    default:
        return idle;
    }
}
