#pragma once
#include <Engine.h>

class CharacterFactory {
public:
    CharacterFactory(Game &game);
    GameObject *create();
private:
    Game &game;
};
