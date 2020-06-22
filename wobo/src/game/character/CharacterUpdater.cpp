#include "CharacterUpdater.h"
#include <algorithm>

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterUpdater::update(int elapsed)
{
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
        this->gameObject->velocity.y = -5;
    }

    if (!this->characterInfo.isGrounded) {
        this->gameObject->velocity.y = std::min(this->gameObject->velocity.y + elapsed * 0.1, 1.);
    } 

    this->characterInfo.isGrounded = false;
}
