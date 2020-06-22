#include "Collider.h"
#include "GameObject.h"

Collider::Collider(int w, int h) : w(w), h(h)
{
}

Collider::Collider(Size size) : Collider(size.w, size.h)
{
}

void Collider::setGameObject(GameObject* gameObject)
{
    Component::setGameObject(gameObject);
}

bool Collider::checkCollision(Collider* collider)
{
    Vector thisPosition = this->gameObject->globalPosition;
    Vector otherPosition = collider->gameObject->globalPosition;
    return Collider::checkCollision(this->w, this->h, thisPosition.x, thisPosition.y, collider->w, collider->h, otherPosition.x, otherPosition.y);
}

bool Collider::checkCollision(int wA, int hA, int xA, int yA, int wB, int hB, int xB, int yB)
{
    if (xA > xB + wB) {
        return false;
    }

    if (xA + wA < xB) {
        return false;
    }

    if (yA > yB + hB) {
        return false;
    }

    if (yA + hA < yB) {
        return false;
    }

    return true;
}


