#include "DamageTaker.h"
#include "DamagedSoundPlayer.h"

DamageTaker::DamageTaker(int health) : health(health)
{
}

void DamageTaker::takeDamage(int damage)
{
    auto damagedSoundPlayer = this->getGameObject()->getComponent<DamagedSoundPlayer>();
    damagedSoundPlayer->play();
    this->health--;
    if (this->health <= 0) {
        this->getGameObject()->game->destroyObject(this->getGameObject());
    }
}
