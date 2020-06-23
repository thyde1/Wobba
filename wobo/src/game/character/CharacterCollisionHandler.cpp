#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collider *collider, Vector &normal)
{
    if (normal.y != 0) {
        this->gameObject->globalPosition.y = collider->getGameObject()->globalPosition.y - this->characterInfo.size.h;
        this->gameObject->velocity.y = 0;
    }

    if (normal.x != 0) {
        this->gameObject->velocity.x = 0;
    }

    this->characterInfo.isGrounded = true;
}
