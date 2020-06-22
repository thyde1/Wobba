#include "CharacterCollisionHandler.h"

CharacterCollisionHandler::CharacterCollisionHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterCollisionHandler::handleCollision(Collider *collider)
{
    this->gameObject->globalPosition.y = collider->y - this->characterInfo.size.h;
    this->characterInfo.isGrounded = true;
}
