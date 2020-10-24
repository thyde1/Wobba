#include "SetLifespanUpdater.h"

SetLifespanUpdater::SetLifespanUpdater(int ttlMilliseconds) : ttlMilliseconds(ttlMilliseconds)
{
}

void SetLifespanUpdater::update(int elapsed)
{
    this->ttlMilliseconds -= elapsed;
    if (this->ttlMilliseconds <= 0) {
        this->getGameObject()->game->destroyObject(this->getGameObject());
    }
}
