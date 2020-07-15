#include "CharacterUpdater.h"
#include <algorithm>
#include "../terrain/SafeSurface.h"

CharacterUpdater::CharacterUpdater(CharacterInfo &characterInfo, Collider &groundCollider, SoundPlayer &jumpSoundPlayer)
    : characterInfo(characterInfo), groundCollider(groundCollider), jumpSoundPlayer(jumpSoundPlayer)
{
}

void CharacterUpdater::update(int elapsed)
{
    const double jumpStrength = 0.2;
    const double runSpeed = 0.1;
    const double runAcceleration = 0.0005;
    const int maxJumpDuration = 100;
    const double gravity = 0.001;
    const double terminalV = 0.2;
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
        this->jumpSoundPlayer.play();
    }

    if (this->characterInfo.jumpHeld && this->jumpDuration >= 0 && this->jumpDuration < maxJumpDuration) {
        this->gameObject->velocity.y = -jumpStrength;
        this->jumpDuration += elapsed;
    }

    if (!this->characterInfo.jumping && !this->characterInfo.jumpHeld) {
        this->jumpDuration = -1;
    }

    auto position = this->gameObject->getGlobalPosition();

    if (!this->characterInfo.jumping && isGrounded && this->gameObject->velocity.y > 0) {
        this->gameObject->velocity.y = 0;
        auto groundObject = groundCollisions.front().colliderB->getGameObject();
        position.y = groundObject->getGlobalPosition().y - this->characterInfo.size.h;
        this->gameObject->setGlobalPosition(position);
        this->jumpSoundPlayer.play();
    }
    else if (!this->characterInfo.jumping && !isGrounded) {
        this->gameObject->velocity.y = std::min(this->gameObject->velocity.y + elapsed * gravity, terminalV);
    }

    this->characterInfo.isGrounded = isGrounded;

    this->updateAttackingStatus(elapsed);
}

void CharacterUpdater::updateAttackingStatus(int elapsed)
{
    if (this->characterInfo.attacking) {
        this->attackDuration += elapsed;
    }

    if (this->characterInfo.attacking && this->attackDuration >= 300) {
        this->characterInfo.attacking = false;
        this->attackDuration = 0;
    }
}
