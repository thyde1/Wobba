#pragma once

#include "Component.h"
#include "Size.h"
#include "Vector.h"

class Collider;

struct CollisionCheckResult {
    bool collisionDetected;
    Vector normal;
};


struct Collision
{
    bool isCollision;
    Vector normal;
    Collider *colliderA;
    Collider *colliderB;
};

class Collider : public Component {
public:
    Collider(Size size, Vector offset);
    Collider(Size size);
    void setGameObject(GameObject *gameObject);
    Collision checkCollision(Collider *collider);
    Size size;
    Vector offset;
    static CollisionCheckResult checkCollision(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB);
    static Vector getCollisionNormal(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB);
};

