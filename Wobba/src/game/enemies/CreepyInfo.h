#pragma once

#include <Engine.h>
#include "../Direction.h"

enum class CreepyColor {
    green,
    blue
};

class CreepyInfo : public Component {
public:
    CreepyInfo(CreepyColor color);
    Direction direction = Direction::RIGHT;
    CreepyColor color;
    double speed;
};
