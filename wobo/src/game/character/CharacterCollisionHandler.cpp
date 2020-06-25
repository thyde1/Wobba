#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collision collision)
{
    auto thisCollider = collision.colliderA;
    auto collider = collision.colliderB;
    auto normal = collision.normal;

    if (!thisCollider->checkCollision(collider).isCollision) {
        // Collision has already been resolved, no need to do so again
        return;
    }

    // Character collider sits one pixel deep in ground so we continuously receive collisions
    auto isGroundedOnCollider =
        this->gameObject->globalPosition.y == collider->getGameObject()->globalPosition.y - this->characterInfo.size.h + 1
        && this->gameObject->velocity.y == 0;

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
