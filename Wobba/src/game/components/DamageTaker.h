#pragma once

#include <Engine.h>
#include "DamagedSoundPlayer.h"

class DamageTaker : public Component {
public:
    DamageTaker(int health, DamagedSoundPlayer &damagedSoundPlayer);
    void takeDamage(int);
private:
    int health;
    DamagedSoundPlayer &damagedSoundPlayer;
};

