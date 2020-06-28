#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class CharacterRenderer : public AnimatedSpriteRenderer {
public:
    CharacterRenderer(CharacterInfo *characterInfo);
private:
    CharacterInfo *characterInfo;
    Animation getAnimation();
    const Animation
        idle = { 0, 1, false },
        walkingRight = { 1, 8, false },
        walkingLeft = { 1, 8, true }, 
        jumpingUp = { 9, 2, false },
        jumpingRight = { 11, 2, false },
        jumpingLeft = { 11, 2, true };
};
