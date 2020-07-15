#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class SwordCollider : public Collider {
public:
    SwordCollider(CharacterInfo &characterInfo);
    Vector getOffset() override;
private:
    CharacterInfo &characterInfo;
};
