#pragma once

#include "GameObject.h"

class Component {
public:
    virtual ~Component();
    GameObject* getGameObject();
    virtual void setGameObject(GameObject* gameObject);
    virtual void init();
protected:
    GameObject *gameObject = nullptr;
};
