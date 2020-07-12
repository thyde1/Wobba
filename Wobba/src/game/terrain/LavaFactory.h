#pragma once
#include "../levelLoader/GameObjectFactory.h"

class LavaFactory : public GameObjectFactory {
public:
    LavaFactory(Game &game);
    GameObject *create(Vector position);
private:
    Game &game;
};
