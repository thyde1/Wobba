#pragma once

#include <Engine.h>
#include "CreepyInfo.h"
#include "../levelLoader/GameObjectFactory.h"

class CreepyFactory : public GameObjectFactory {
public:
    CreepyFactory(Game &game, CreepyColor creepyColor);
    GameObject *create(Vector position);
private:
    Game &game;
    CreepyColor creepyColor;
};
