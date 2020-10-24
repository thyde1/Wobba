#include "CharacterRenderer.h"

CharacterRenderer::CharacterRenderer(CharacterInfo *characterInfo) :
    AnimatedSpriteRenderer(
        "assets/character.png",
        { 8, 8 },
        { 8, 8 }),
    characterInfo(characterInfo)
{
}

Animation CharacterRenderer::getAnimation()
{
    if (this->characterInfo->attacking && this->characterInfo->lastMovementDirection == Direction::LEFT) {
        return attackingLeft;
    }
    else if (this->characterInfo->attacking && this->characterInfo->lastMovementDirection == Direction::RIGHT) {
        return attackingRight;
    }

    if (!this->characterInfo->isGrounded) {
        switch (this->characterInfo->currentMovementDirection) {
        case Direction::LEFT:
            return jumpingLeft;
        case Direction::RIGHT:
            return jumpingRight;
        default:
            return jumpingUp;
        }
    }

    switch (this->characterInfo->currentMovementDirection) {
    case Direction::LEFT:
        return walkingLeft;
    case Direction::RIGHT:
        return walkingRight;
    default:
        if (this->characterInfo->lastMovementDirection == Direction::LEFT) {
            return idleLeft;
        }
        else if (this->characterInfo->lastMovementDirection == Direction::RIGHT) {
            return idleRight;
        }
    }
}
