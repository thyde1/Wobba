#pragma once

#include "Engine.h"

class SetLifespanUpdater : public Updater {
public:
    SetLifespanUpdater(int ttlMilliseconds);
    void update(int elapsed);
private:
    int ttlMilliseconds;
};
