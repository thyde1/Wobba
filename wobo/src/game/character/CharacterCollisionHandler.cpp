#include "CharacterCollisionHandler.h"
#include <iostream>

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

    if (collider->getGameObject() == this->getGameObject()) {
        // Don't collide with one of our own colliders
        return;
    }

    if (normal.y != 0) {
        std::cout << "y";
        this->gameObject->globalPosition.y = collider->getGameObject()->globalPosition.y - thisCollider->size.h;
    }

    if (normal.x != 0) {
       std::cout << "x";
        if (normal.x < 0) {
            this->gameObject->globalPosition.x = collider->getGameObject()->globalPosition.x - this->characterInfo.size.w;
        }
        else
        {
            this->gameObject->globalPosition.x = collider->getGameObject()->globalPosition.x + collider->size.w;
        }
    }
}
