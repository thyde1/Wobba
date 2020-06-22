#include "GameObject.h"
#include "InputHandler.h"
#include "Updater.h"
#include "GameCollider.h"
#include "Collider.h"
#include "CollisionHandler.h"
#include "Renderer.h"

GameObject::GameObject(Game *game, SDL_Renderer *renderer) : globalPosition({0, 0})
{
    this->game = game;
    this->sdlRenderer = renderer;
}

GameObject::~GameObject()
{
    for (auto component : this->components)
    {
        delete component;
    }
}

void GameObject::handleInput(std::list<SDL_Keysym> keys)
{
    for (auto inputHandler : this->inputHandlers)
    {
        inputHandler->handleInput(keys);
    }
}

void GameObject::update(int elapsed)
{
    for (auto updater : this->updaters)
    {
        updater->update(elapsed);
    }
    for (auto gameCollider : this->colliders) {
        gameCollider->collider->x = this->globalPosition.x;
        gameCollider->collider->y = this->globalPosition.y;
    }
}

void GameObject::checkCollision(GameObject* object)
{
    for (auto gameCollider : this->colliders)
    {
        if (gameCollider->type == ColliderType::ACTIVE) {
            object->checkCollision(gameCollider->collider);
        }
    }
}

void GameObject::checkCollision(Collider* collider)
{
    for (auto gameCollider : this->colliders)
    {
        auto thisCollider = gameCollider->collider;
        if (thisCollider->checkCollision(collider)) {
            this->handleCollision(collider);
            collider->getGameObject()->handleCollision(thisCollider);
        }
    }
}

void GameObject::handleCollision(Collider *collider)
{
    for (auto collisionHandler : this->collisionHandlers)
    {
        collisionHandler->handleCollision(collider);
    }
}

void GameObject::render()
{
    for (Renderer *renderer : this->renderers)
    {
        renderer->render();
    }
}

GameObject *GameObject::addUpdater(Updater *updater)
{
    this->addComponent(updater);
    this->updaters.push_back(updater);
    return this;
}

GameObject *GameObject::addRenderer(Renderer *renderer)
{
    this->addComponent(renderer);
    renderer->setSdlRenderer(this->sdlRenderer);
    this->renderers.push_back(renderer);
    return this;
}

GameObject *GameObject::addInputHandler(InputHandler *inputHandler)
{
    this->addComponent(inputHandler);
    this->inputHandlers.push_back(inputHandler);
    return this;
}

GameObject *GameObject::addCollisionHandler(CollisionHandler *collisionHandler)
{
    this->addComponent(collisionHandler);
    this->collisionHandlers.push_back(collisionHandler);
    return this;
}

GameObject *GameObject::addCollider(ColliderType type, Collider *collider) {

    this->addComponent(collider);
    GameCollider* gameCollider = new GameCollider(type, collider);
    this->colliders.push_back(gameCollider);
    return this;
}

GameObject *GameObject::addComponent(Component *component)
{
    component->setGameObject(this);
    this->components.push_back(component);
    return this;
}

GameObject *GameObject::setGlobalPosition(Vector position)
{
    this->globalPosition = position;
    return this;
}
