#pragma once
#include <Engine.h>

class DeathScreenFactory {
public:
    DeathScreenFactory(Game &game);
    GameObject *create();
private:
    Game &game;
};
