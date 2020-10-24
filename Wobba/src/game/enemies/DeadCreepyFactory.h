#pragma once

#include "Engine.h"

class DeadCreepyFactory {
public:
    DeadCreepyFactory(Game &game);
    GameObject *Create(Vector position);

private:
    Game &game;
};
