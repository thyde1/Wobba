#include "FireballUpdater.h"
#include <cmath>

FireballUpdater::FireballUpdater(double xCenter, double startingProgress) : xCenter(xCenter), currentPhaseDuration((int)(startingProgress * this->phaseMilliseconds))
{
}

void FireballUpdater::update(int elapsed)
{
    this->currentPhaseDuration += elapsed;
    this->currentPhaseDuration = currentPhaseDuration % this->phaseMilliseconds;
    auto progress = (double)this->currentPhaseDuration / (double)this->phaseMilliseconds;
    auto position = this->gameObject->getGlobalPosition();
    position.y = (1 - std::sin(progress * M_PI)) * 90 + 10;
    this->gameObject->setGlobalPosition(position);
}
