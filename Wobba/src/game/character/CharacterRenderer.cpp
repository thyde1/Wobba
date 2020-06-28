#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(CharacterInfo *characterInfo) :
    AnimatedSpriteRenderer(
        "assets/character2.png",
        { 8, 8 },
        { 80, 80 },
        std::map<const char *, Animation>({ { "Idle", { 0, 1, false } }, { "WalkingRight", { 1, 8, false } }, { "WalkingLeft", { 1, 8, true } }, { "Jumping", { 9, 2, true } } })),
    characterInfo(characterInfo)
{
}

const char *CharacterRenderer::getAnimation()
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
