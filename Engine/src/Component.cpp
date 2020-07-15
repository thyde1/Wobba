#include "Component.h"

unsigned int Component::nextId{ 0 };

void Component::init()
{
}

unsigned int Component::getId()
{
    return this->id;
}

Component::Component()
{
    static unsigned int nextId = 0;
    this->id = Component::nextId;
    Component::nextId++;
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

