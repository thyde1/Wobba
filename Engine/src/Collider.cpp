#include "Collider.h"
#include "GameObject.h"

Collider::Collider(int w, int h) : x(0), y(0), w(w), h(h)
{
}

Collider::Collider(Size size) : Collider(size.w, size.h)
{
}

void Collider::setGameObject(GameObject* gameObject)
{
    Component::setGameObject(gameObject);
    this->x = gameObject->globalPosition.x;
    this->y = gameObject->globalPosition.y;
}

bool Collider::checkCollision(Collider* collider)
{
    return Collider::checkCollision(this->w, this->h, this->x, this->y, collider->w, collider->h, collider->x, collider->y);
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


