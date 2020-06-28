#include "FireballUpdater.h"

void FireballUpdater::update(int elapsed)
{
    if (this->gameObject->globalPosition.y < 0) {
        this->gameObject->globalPosition.y = 800;
        return;
    }

    this->gameObject->globalPosition.y -= elapsed;
}
