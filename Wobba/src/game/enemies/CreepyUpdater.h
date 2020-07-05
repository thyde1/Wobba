#pragma once

#include <Engine.h>
#include "CreepyInfo.h"

class CreepyUpdater : public Updater {
public:
    CreepyUpdater(CreepyInfo &creepyInfo, int baseX, double range);
    void update(int elapsed);
private:
    double range;
    double currentOffset = 0;
    int baseX;
    CreepyInfo &creepyInfo;
};
