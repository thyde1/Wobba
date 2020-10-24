#include "DamageTaker.h"

DamageTaker::DamageTaker(int health) : health(health)
{
}

void DamageTaker::takeDamage(int damage)
{
    this->health--;
    if (this->health <= 0) {
        this->getGameObject()->game->destroyObject(this->getGameObject());
    }
}
