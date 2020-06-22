#pragma once
#include <Engine.h>

class TerrainFactory {
public:
    TerrainFactory(Game &game);
    GameObject* create(Position position);
private:
    Game &game;
};
