#include "Collider.h"
#include "GameObject.h"

Collider::Collider(int w, int h) : size({ w, h })
{
}

Collider::Collider(Size size) : size(size)
{
}

void Collider::setGameObject(GameObject* gameObject)
{
    Component::setGameObject(gameObject);
}

CollisionCheckResult Collider::checkCollision(Collider* collider)
{
    Vector thisPosition = this->gameObject->globalPosition;
    Vector thisVelocity = this->gameObject->velocity;
    Vector otherPosition = collider->gameObject->globalPosition;
    Vector otherVelocity = collider->gameObject->velocity;
    return Collider::checkCollision(
        this->size, thisPosition, thisVelocity, collider->size, otherPosition);
}

CollisionCheckResult Collider::checkCollision(Size sizeA, Vector posA, Vector velA, Size sizeB, Vector posB)
{
    if (posA.x > posB.x + sizeB.w) {
        return { false, { 0, 0 } };
    }

    if (posA.x + sizeA.w < posB.x) {
        return { false, { 0, 0 } };
    }

    if (posA.y > posB.y + sizeB.h) {
        return { false, { 0, 0 } };
    }

    if (posA.y + sizeA.h < posB.y) {
        return { false, { 0, 0 } };
    }

    return { true, { 0, -1 } };
}

Vector Collider::getCollisionNormal(Size sizeA, Vector posA, Vector velA, Size sizeB, Vector posB)
{
    return { 0, -1 };
}
