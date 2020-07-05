#include "CharacterCollisionHandler.h"
#include <iostream>
#include "../terrain/Damager.h"

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

    if (collider->getGameObject()->hasComponent<Damager>()) {
        auto characterInfo = this->gameObject->getComponent<CharacterInfo>();
        characterInfo->alive = false;
    }

    auto position = this->gameObject->getGlobalPosition();

    if (normal.y != 0) {
        if (normal.y < 0) {
            position.y = collider->getGameObject()->getGlobalPosition().y - thisCollider->size.h;
        }
        else {
            position.y = collider->getGameObject()->getGlobalPosition().y + collider->size.h;
        }
    }

    if (normal.x != 0) {
        if (normal.x < 0) {
            position.x = collider->getGameObject()->getGlobalPosition().x - this->characterInfo.size.w;
        }
        else
        {
            position.x = collider->getGameObject()->getGlobalPosition().x + collider->size.w;
        }
    }

    collider->getGameObject()->setGlobalPosition(position);
}
