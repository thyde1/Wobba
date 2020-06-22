#pragma once

#include "Engine.h"
#include "CharacterInfo.h"

class CharacterCollisionHandler : public CollisionHandler {
public:
    CharacterCollisionHandler(CharacterInfo &characterInfo);
    void handleCollision(Collider *collider);
private:
    CharacterInfo &characterInfo;
};
