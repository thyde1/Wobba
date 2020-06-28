#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class CharacterRenderer : public AnimatedSpriteRenderer {
public:
    CharacterRenderer(CharacterInfo *characterInfo);
private:
    CharacterInfo *characterInfo;
    const char *getAnimation();
    const char *jumping = "Jumping";
    const char *walkingLeft = "WalkingLeft";
    const char *walkingRight = "WalkingRight";
    const char *idle = "Idle";
};
