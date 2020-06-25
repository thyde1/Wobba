#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collider *collider, Vector &normal)
{
    // Character collider sits one pixel deep in ground so we continuously receive collisions
    auto isGroundedOnCollider = this->gameObject->globalPosition.y == collider->getGameObject()->globalPosition.y - this->characterInfo.size.h + 1;

    if (normal.y != 0 || isGroundedOnCollider) {
        this->gameObject->velocity.y = 0;
        this->gameObject->globalPosition.y = collider->getGameObject()->globalPosition.y - this->characterInfo.size.h + 1;
        this->characterInfo.isGrounded = true;
    }

    if (normal.x != 0 && !isGroundedOnCollider) {
        this->gameObject->velocity.x = 0;

        if (normal.x < 0) {
            this->gameObject->globalPosition.x = collider->getGameObject()->globalPosition.x - this->characterInfo.size.w;
        }
        else
        {
            this->gameObject->globalPosition.x = collider->getGameObject()->globalPosition.x + collider->size.w;
        }
    }
}
