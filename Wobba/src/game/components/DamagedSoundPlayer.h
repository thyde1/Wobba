#pragma once

#include <string>

#include "Engine.h"

class DamagedSoundPlayer : public Component {
public:
    DamagedSoundPlayer(const char *file);
    void play();

private:
    SoundPlayer soundPlayer;
};
