#pragma once

#include <Engine.h>
#include "CharacterInfo.h"

class CharacterUpdater : public Updater {
public:
    CharacterUpdater(CharacterInfo &characterInfo);
    void update(int elapsed);
private:
    CharacterInfo &characterInfo;
};
