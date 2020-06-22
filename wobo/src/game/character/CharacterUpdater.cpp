#include "CharacterUpdater.h"
#include <algorithm>

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterUpdater::update(int elapsed)
{
    if (this->characterInfo.direction == Direction::LEFT) {
        this->gameObject->globalPosition.x -= elapsed / 5;
    }

    if (this->characterInfo.direction == Direction::RIGHT) {
        this->gameObject->globalPosition.x += elapsed / 5;
    }

    if (this->characterInfo.jumping && this->characterInfo.isGrounded) {
        this->characterInfo.velocity.y = -10;
    }

    if (!this->characterInfo.isGrounded) {
        this->characterInfo.velocity.y = std::min(this->characterInfo.velocity.y + elapsed / 10, 7);
    }

    this->gameObject->globalPosition += this->characterInfo.velocity;

    this->characterInfo.isGrounded = false;
}
