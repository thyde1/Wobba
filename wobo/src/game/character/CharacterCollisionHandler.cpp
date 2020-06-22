#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collider *collider)
{
    this->gameObject->globalPosition.y = collider->getGameObject()->globalPosition.y - this->characterInfo.size.h;
    this->gameObject->velocity.y = 0;
    this->characterInfo.isGrounded = true;
}
