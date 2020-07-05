#pragma once
#include <Engine.h>

class FireballFactory {
public:
    FireballFactory(Game &game);
    GameObject *create(Vector position);
private:
    Game &game;
};
