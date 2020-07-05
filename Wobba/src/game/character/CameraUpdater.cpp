#include "CameraUpdater.h"

void CameraUpdater::update(int elapsed)
{
    this->gameObject->game->cameraPosition = Vector{ this->gameObject->getGlobalPosition().x - 50, 0 };
}
