#pragma once

#include "SDL.h"
#include "Component.h"

class InputHandler : public Component {
public:
    virtual void handleInput(std::list<SDL_Keysym> keys) = 0;
};
