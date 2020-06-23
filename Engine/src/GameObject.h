#pragma once

#include "SDL.h"
#include <list>
#include "Vector.h"
#include "GameCollider.h"

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
    Game* game;
    void update(int elapsed);
    void checkCollision(GameObject *object);
    virtual void handleCollision(Collider *collider, Vector &normal);
    void handleInput(std::list<SDL_Keysym> keys);
    void render();
    GameObject* addUpdater(Updater *updater);
    GameObject* addRenderer(Renderer *renderer);
    GameObject* addInputHandler(InputHandler *inputHandler);
    GameObject* addCollisionHandler(CollisionHandler *collisionHandler);
    GameObject* addCollider(ColliderType type, Collider *collider);
    GameObject* addComponent(Component *component);
    GameObject* setGlobalPosition(Vector position);
    template <class T>
    T getComponent()
    {
        for (auto component : this->components)
        {
            T castComponent = dynamic_cast<T>(component);
            if (castComponent != NULL) {
                return castComponent;
            }
        }

        return NULL;
    }
    Vector globalPosition;
    Vector velocity;
private:
    void checkCollision(Collider *collider);
    SDL_Renderer *sdlRenderer;
    std::list<Updater*> updaters;
    std::list<Renderer*> renderers;
    std::list<InputHandler*> inputHandlers;
    std::list<CollisionHandler*> collisionHandlers;
    std::list<GameCollider*> colliders;
    std::list<Component*> components;
};
