#pragma once
#include <Engine.h>

class LavaFactory {
public:
    LavaFactory(Game &game);
    GameObject *create(Vector position);
private:
    Game &game;
};
