#pragma once

#include <Engine.h>
#include "../levelLoader/GameObjectFactory.h"

class FireballFactory : public GameObjectFactory {
public:
    FireballFactory(Game &game);
    GameObject *create(Vector position);
private:
    Game &game;
};
