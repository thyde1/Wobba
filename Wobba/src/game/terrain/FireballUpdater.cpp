#include "FireballUpdater.h"
#include <cmath>

FireballUpdater::FireballUpdater(double xCenter, double startingProgress) : xCenter(xCenter), currentPhaseDuration(startingProgress * this->phaseMilliseconds)
{
}

void FireballUpdater::update(int elapsed)
{
    this->currentPhaseDuration += elapsed;
    this->currentPhaseDuration = currentPhaseDuration % this->phaseMilliseconds;
    auto progress = (double)this->currentPhaseDuration / (double)this->phaseMilliseconds;
    this->gameObject->globalPosition.y = (1 - std::sin(progress * M_PI)) * 900 + 100;
}
