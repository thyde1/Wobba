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
        idleRight = { 0, 1, false },
        idleLeft = { 0, 1, true },
        walkingRight = { 1, 8, false },
        walkingLeft = { 1, 8, true }, 
        jumpingUp = { 9, 2, false },
        jumpingRight = { 11, 2, false },
        jumpingLeft = { 11, 2, true },
        attackingRight = { 13, 3, false },
        attackingLeft = { 13, 3, true };
};
