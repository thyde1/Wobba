#include "WinCollisionHandler.h"
#include "../character/CharacterInfo.h"
#include "../ui/WinScreenFactory.h"

void WinCollisionHandler::handleCollision(Collision collision)
{
    if (collision.colliderB->getGameObject()->getComponent<CharacterInfo>() != NULL) {
        WinScreenFactory(*collision.colliderA->getGameObject()->game).create();
        collision.colliderB->getGameObject()->game->destroyObject(collision.colliderB->getGameObject());
    }
}
