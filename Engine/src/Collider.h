#pragma once

#include "Component.h"
#include "Size.h"

struct CollisionCheckResult {
    bool collisionDetected;
    Vector normal;
};

struct Collision {
    bool isCollision;
    Vector normal;
    Collider *colliderA;
    Collider *colliderB;
};

class Collider : public Component {
public:
    Collider(int w, int h);
    Collider(Size size);
    void setGameObject(GameObject *gameObject);
    Collision checkCollision(Collider *collider);
    Size size;
    static CollisionCheckResult checkCollision(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB);
    static Vector getCollisionNormal(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB);
};

