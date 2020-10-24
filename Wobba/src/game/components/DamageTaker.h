#pragma once

#include <Engine.h>

class DamageTaker : public Component {
public:
    DamageTaker(int health);
    void takeDamage(int);
private:
    int health;
};

