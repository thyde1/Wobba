#pragma once
#include <list>
#include "SDL.h"
#include "Component.h"

class GameObject;

class Updater : public Component {
public:
    virtual void update(int elapsed) = 0;
};
