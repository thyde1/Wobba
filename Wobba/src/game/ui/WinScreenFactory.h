#pragma once

#include "Engine.h"

class WinScreenFactory {
public:
    WinScreenFactory(Game &game);
    GameObject *create();
private:
    Game &game;
};
