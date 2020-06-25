#include "Collider.h"
#include "GameObject.h"

Collider::Collider(int w, int h) : size({ w, h })
{
}

Collider::Collider(Size size) : size(size)
{
}

void Collider::setGameObject(GameObject *gameObject)
{
    Component::setGameObject(gameObject);
}

Collision Collider::checkCollision(Collider *collider)
{
    Vector thisPosition = this->gameObject->globalPosition;
    Vector thisVelocity = this->gameObject->velocity;
    Vector otherPosition = collider->gameObject->globalPosition;
    Vector otherVelocity = collider->gameObject->velocity;
    auto collisionDetails = Collider::checkCollision(
        this->size, thisPosition, thisVelocity, collider->size, otherPosition);
    return Collision{ collisionDetails.collisionDetected, collisionDetails.normal, this, collider };
}

CollisionCheckResult Collider::checkCollision(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB)
{
    if (posA.x >= posB.x + sizeB.w) {
        return { false, { 0, 0 } };
    }

    if (posA.x + sizeA.w <= posB.x) {
        return { false, { 0, 0 } };
    }

    if (posA.y >= posB.y + sizeB.h) {
        return { false, { 0, 0 } };
    }

    if (posA.y + sizeA.h <= posB.y) {
        return { false, { 0, 0 } };
    }

    auto pastPos = posA - (velA * 100);
    auto collisionNormal = Collider::getCollisionNormal(sizeA, pastPos, velA, sizeB, posB);

    return { true, collisionNormal };
}

Vector Collider::getCollisionNormal(Size &sizeA, Vector &posA, Vector &velA, Size &sizeB, Vector &posB)
{
    if (velA == Vector{ 0, 0 }) {
        return { 0, 0 };
    }

    if (posA.y + sizeA.h <= posB.y) {
        // Top side
        if (posA.x + sizeA.w < posB.x) {
            // Top left
            Vector topLeftVel = posB - (posA + sizeA.toVector());
            if (velA.normalize().y > topLeftVel.normalize().y) {
                return { -1, 0 };
            }
            else {
                return { 0, -1 };
            }
        }
        else if (posA.x > posB.x + sizeB.w)
        {
            // Top right
            Vector topRightVel = (posB + Vector{ (double)sizeB.w, 0 }) - (posA + Vector{ 0, (double)sizeA.h });
            if (velA.normalize().y > topRightVel.normalize().y) {
                return { 1, 0 };
            }
            else {
                return { 0, -1 };
            }
        }
        else
        {
            // Top middle
            return { 0, -1 };
        }
    }
    else if (posA.y + sizeA.h <= posB.y) {
        // Bottom side
        if (posA.x + sizeA.w < posB.x) {
            // Bottom left
            Vector bottomLeftVel = (posB + Vector{ 0, (double)sizeB.h }) - (posA + Vector{ (double)sizeA.w, 0 });
            if (velA.normalize().y < bottomLeftVel.normalize().y) {
                return { -1, 0 };
            }
            else {
                return { 0, 1 };
            }
        }
        else if (posA.x > posB.x + sizeB.w) {
            // Bottom right
            Vector bottomRightVel = (posB + sizeB.toVector()) - posA;
            if (velA.normalize().y < bottomRightVel.normalize().y) {
                return { 1, 0 };
            }
            else {
                return { 0, 1 };
            }
        }
        else {
            // Bottom middle
            return { 0, 1 };
        }
    }
    else {
        // To the side
        if (posA.x < posB.x) {
            return { -1, 0 };
        }
        else {
            return { 1, 0 };
        }
    }
}
