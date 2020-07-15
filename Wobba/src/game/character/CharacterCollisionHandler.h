#pragma once

#include "Engine.h"
#include "CharacterInfo.h"

class CharacterCollisionHandler : public CollisionHandler {
public:
    CharacterCollisionHandler(CharacterInfo &characterInfo, Collider &swordCollider);
    void handleCollision(Collision collision);
private:
    CharacterInfo &characterInfo;
    Collider &swordCollider;
    void handleSwordCollision(Collider *collider);
};
