#pragma once

class GameObject;

class Component {
public:
    static unsigned int nextId;
    Component();
    virtual ~Component();
    GameObject* getGameObject();
    virtual void setGameObject(GameObject* gameObject);
    virtual void init();
    unsigned int getId();
protected:
    GameObject *gameObject = nullptr;
private:
    unsigned int id;
};
