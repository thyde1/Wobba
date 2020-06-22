#pragma once
#include <Engine.h>

class TerrainFactory {
public:
    TerrainFactory(Game &game);
    GameObject* create(Vector position);
private:
    Game &game;
};
