#pragma once

#include <Engine.h>

class DeadInputHandler : public InputHandler {
public:
    void handleInput(std::list<SDL_Keysym> keys);
};
