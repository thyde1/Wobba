#pragma once

#include "Collider.h"
#include "Component.h"

class CollisionHandler : public Component {
public:
    virtual void handleCollision(Collider *collider) = 0;
};
