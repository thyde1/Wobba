#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class SwordRenderer : public SpriteRenderer {
public:
    SwordRenderer(CharacterInfo &characterInfo);
    void render();
    GVector<int> getOffset();
private:
    CharacterInfo &characterInfo;
};
