#include "CharacterUpdater.h"
#include <algorithm>

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterUpdater::update(int elapsed)
{
    const int jumpStrength = 2;
    const double runSpeed = 1;
    const double runAcceleration = 0.005;
    const int maxJumpDuration = 100;
    const double gravity = 0.05;
    if (this->characterInfo.direction == Direction::LEFT) {
        this->gameObject->velocity.x = std::max(std::min(this->gameObject->velocity.x - elapsed * runAcceleration, 0.), -runSpeed);
    }

    if (this->characterInfo.direction == Direction::RIGHT) {
        this->gameObject->velocity.x = std::min(std::max(this->gameObject->velocity.x + elapsed * runAcceleration, 0.), runSpeed);
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
        this->gameObject->velocity.y = std::min(this->gameObject->velocity.y + elapsed * gravity, 0.9);
    }

    this->characterInfo.isGrounded = false;
}
