#pragma once

#include "Engine.h"
#include "CharacterInfo.h"

class CharacterCollisionHandler : public CollisionHandler {
public:
    CharacterCollisionHandler(CharacterInfo &characterInfo);
    void handleCollision(Collision collision);
private:
    CharacterInfo &characterInfo;
};
