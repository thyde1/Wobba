#include "Component.h"

void Component::init()
{
}

Component::~Component()
{
}

GameObject* Component::getGameObject()
{
    return this->gameObject;
}

void Component::setGameObject(GameObject* gameObject)
{
    this->gameObject = gameObject;
}
