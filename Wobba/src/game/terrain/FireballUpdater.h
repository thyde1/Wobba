#pragma once

#include <Engine.h>

class FireballUpdater : public Updater {
public:
    FireballUpdater(double xCenter, double startingProgress);
    void update(int elapsed);
private:
    const int phaseMilliseconds = 1000;
    int currentPhaseDuration = 0;
    double xCenter;
};
