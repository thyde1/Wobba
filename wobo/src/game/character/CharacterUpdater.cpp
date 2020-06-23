#include "CharacterUpdater.h"
#include <algorithm>

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterUpdater::update(int elapsed)
{
    const int jumpStrength = 2;
    const int maxJumpDuration = 100;
    const double gravity = 0.05;
    if (this->characterInfo.direction == Direction::LEFT) {
        this->gameObject->velocity.x = -elapsed / 10;
    }

    if (this->characterInfo.direction == Direction::RIGHT) {
        this->gameObject->velocity.x = elapsed / 10;
    }

    if (this->characterInfo.direction == Direction::NONE) {
        this->gameObject->velocity.x = 0;
    }

    if (this->characterInfo.jumping && this->characterInfo.isGrounded) {
        this->gameObject->velocity.y = -jumpStrength;
        this->jumpDuration = 0;
    }

    if (this->characterInfo.jumpHeld && this->jumpDuration >= 0 && this->jumpDuration < maxJumpDuration) {
        this->gameObject->velocity.y = -jumpStrength;
        this->jumpDuration += elapsed;
    }

    if (!this->characterInfo.jumping && !this->characterInfo.jumpHeld) {
        this->jumpDuration = -1;
    }

    if (!this->characterInfo.isGrounded) {
        this->gameObject->velocity.y = std::min(this->gameObject->velocity.y + elapsed * gravity, 1.);
    } 

    this->characterInfo.isGrounded = false;
}
