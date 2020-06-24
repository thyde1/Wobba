#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collider *collider, Vector &normal)
{
    if (normal.y != 0) {
        this->gameObject->velocity.y = 0;
        this->gameObject->globalPosition.y = collider->getGameObject()->globalPosition.y - this->characterInfo.size.h;
        this->characterInfo.isGrounded = true;
    }

    if (normal.x != 0) {
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
