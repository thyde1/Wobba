#pragma once

#include "SDL.h"
#include <list>
#include <map>
#include <bitset>
#include "Vector.h"
#include "GameCollider.h"

struct Collision;
class Game;
class Component;
class Updater;
class Renderer;
class InputHandler;
class CollisionHandler;

class GameObject {
public:
    GameObject(Game* game, SDL_Renderer *renderer);
    virtual ~GameObject();
    Game *game;
    void update(int elapsed);
    Collision checkCollision(GameObject *object);
    Collision checkCollision(Collider &collider);
    virtual void handleCollision(Collision collision);
    void handleInput(std::list<SDL_Keysym> keys);
    void render();
    GameObject* addUpdater(Updater *updater);
    GameObject* addRenderer(Renderer *renderer);
    GameObject* addInputHandler(InputHandler *inputHandler);
    GameObject* addCollisionHandler(CollisionHandler *collisionHandler);
    GameObject* addCollider(ColliderType type, Collider *collider);
    template <typename T>
    GameObject * addComponent(T *component)
    {
        component->setGameObject(this);
        auto componentTypeId = getComponentTypeId<T>();
        this->components.insert({ componentTypeId, component });
        this->componentsBitset.set(componentTypeId, true);
        return this;
    }
    GameObject* setGlobalPosition(Vector position);
    template <class T>
    T getComponent()
    {
        auto componentTypeId = getComponentTypeId<T>();
        if (this->componentsBitset[componentTypeId]) {
            return this->components[componentTypeId];
        }

        return NULL;
    }
    Vector globalPosition;
    Vector velocity;
private:
    SDL_Renderer *sdlRenderer;
    std::list<Updater *> updaters;
    std::list<Renderer *> renderers;
    std::list<InputHandler *> inputHandlers;
    std::list<CollisionHandler *> collisionHandlers;
    std::list<GameCollider *> colliders;
    std::map<int, Component *> components;
    std::bitset<128> componentsBitset;
    static int getNewComponentTypeId()
    {
        static int lastId = 0;
        return lastId++;
    }

    template <typename T>
    static int getComponentTypeId()
    {
        static int typeId = getNewComponentTypeId();
        return typeId;
    };
};
