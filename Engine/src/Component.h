#pragma once

class GameObject;

class Component {
public:
    virtual ~Component();
    GameObject* getGameObject();
    virtual void setGameObject(GameObject* gameObject);
    virtual void init();
protected:
    GameObject *gameObject = nullptr;
};
