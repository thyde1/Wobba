#pragma once

#include "Engine.h"

class WinCollisionHandler : public CollisionHandler {
public:
    void handleCollision(Collision collision);
};
