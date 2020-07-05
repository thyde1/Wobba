#pragma once

#include <Engine.h>
#include "CreepyInfo.h"

class CreepyFactory {
public:
    CreepyFactory(Game &game);
    GameObject *create(Vector position, CreepyColor color);
private:
    Game &game;
};
