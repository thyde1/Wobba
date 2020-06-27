#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class CharacterInputHandler : public InputHandler {
public:
    CharacterInputHandler(CharacterInfo &characterInfo);
    void handleInput(std::list<SDL_Keysym> keys);
private:
    CharacterInfo &characterInfo;
};
