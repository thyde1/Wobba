#include "DeathChecker.h"
#include "CharacterInfo.h"
#include "../ui/DeathScreenFactory.h"

void DeathChecker::update(int elapsed)
{
    if (this->gameObject->getGlobalPosition().y > 100 || !this->gameObject->getComponent<CharacterInfo>()->alive) {
        DeathScreenFactory deathScreenFactory(*this->gameObject->game);
        deathScreenFactory.create();

        this->gameObject->game->destroyObject(this->gameObject);
    }
}
