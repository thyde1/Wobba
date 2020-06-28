#include "CharacterUpdater.h"
#include <algorithm>
#include "../terrain/SafeSurface.h"

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo, Collider &groundCollider) : characterInfo(characterInfo), groundCollider(groundCollider)
{
}

void CharacterUpdater::update(int elapsed)
{
    const double jumpStrength = 2;
    const double runSpeed = 1;
    const double runAcceleration = 0.005;
    const int maxJumpDuration = 100;
    const double gravity = 0.01;
    auto groundCollisions = this->gameObject->game->checkCollisions(this->groundCollider);
    bool isGrounded = false;
    for (auto collider : groundCollisions) {
        if (collider.colliderB->getGameObject()->hasComponent<SafeSurface>()) {
            isGrounded = true;
        }
    }

    if (this->characterInfo.direction == Direction::LEFT) {
        this->gameObject->velocity.x = std::max(std::min(this->gameObject->velocity.x - elapsed * runAcceleration, 0.), -runSpeed);
    }

    if (this->characterInfo.direction == Direction::RIGHT) {
        this->gameObject->velocity.x = std::min(std::max(this->gameObject->velocity.x + elapsed * runAcceleration, 0.), runSpeed);
    }

    if (this->characterInfo.direction == Direction::NONE) {
        this->gameObject->velocity.x = 0;
    }

    if (this->characterInfo.jumping && isGrounded) {
        this->gameObject->velocity.y = -jumpStrength;
        this->jumpDuration = 0;
        this->characterInfo.isGrounded = false;
    }

    if (this->characterInfo.jumpHeld && this->jumpDuration >= 0 && this->jumpDuration < maxJumpDuration) {
        this->gameObject->velocity.y = -jumpStrength;
        this->jumpDuration += elapsed;
    }

    if (!this->characterInfo.jumping && !this->characterInfo.jumpHeld) {
        this->jumpDuration = -1;
    }

    if (!this->characterInfo.jumping && isGrounded && this->gameObject->velocity.y >= 0) {
        this->gameObject->velocity.y = 0;
        auto groundObject = groundCollisions.front().colliderB->getGameObject();
        this->gameObject->globalPosition.y = groundObject->globalPosition.y - this->characterInfo.size.h;
    }
    else {
        this->gameObject->velocity.y = std::min(this->gameObject->velocity.y + elapsed * gravity, 2.);
    }
}
