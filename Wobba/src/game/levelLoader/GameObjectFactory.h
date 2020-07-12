#pragma once

#include <Engine.h>

class GameObjectFactory {
public:
    virtual GameObject *create(Vector position);
};
