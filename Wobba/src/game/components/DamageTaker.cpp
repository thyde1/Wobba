#include "DamageTaker.h"
#include "../enemies/DeadCreepyFactory.h"

DamageTaker::DamageTaker(int health, DamagedSoundPlayer &damagedSoundPlayer) : health(health), damagedSoundPlayer(damagedSoundPlayer)
{
}

void DamageTaker::takeDamage(int damage)
{
    this->damagedSoundPlayer.play();
    DeadCreepyFactory(*this->getGameObject()->game).Create(this->getGameObject()->getGlobalPosition());
    this->health--;
    if (this->health <= 0) {
        this->getGameObject()->game->destroyObject(this->getGameObject());
    }
}
