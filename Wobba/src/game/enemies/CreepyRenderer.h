#pragma once

#include <Engine.h>
#include "CreepyInfo.h"

class CreepyRenderer : public AnimatedSpriteRenderer {
public:
    CreepyRenderer(CreepyInfo &creepyInfo);
    Animation getAnimation();
private:
    CreepyInfo &creepyInfo;
    const Animation
        walkingRight = { 0, 2, false },
        walkingLeft = { 0, 2, true };
    static const char *getSprite(CreepyColor color);
};
