#pragma once
#include "../levelLoader/GameObjectFactory.h"

class TerrainFactory : public GameObjectFactory {
public:
    TerrainFactory(Game &game);
    GameObject* create(Vector position) override;
private:
    Game &game;
};
