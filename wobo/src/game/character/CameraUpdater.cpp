#include "CameraUpdater.h"

void CameraUpdater::update(int elapsed)
{
    this->gameObject->game->cameraPosition = Vector{ this->gameObject->globalPosition.x - 500, 0 };
}
