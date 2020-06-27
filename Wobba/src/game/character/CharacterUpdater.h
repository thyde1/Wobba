#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class CharacterUpdater : public Updater {
public:
    CharacterUpdater(CharacterInfo &characterInfo, Collider &groundCollider);
    void update(int elapsed);
    int jumpDuration = -1;
private:
    CharacterInfo &characterInfo;
    Collider &groundCollider;
};
