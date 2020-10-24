#include <algorithm>

#include "GameObject.h"
#include "InputHandler.h"
#include "Updater.h"
#include "GameCollider.h"
#include "Collider.h"
#include "CollisionHandler.h"
#include "Renderer.h"
#include "Game.h"

GameObject::GameObject(Game *game, SDL_Renderer *renderer) : globalPosition({0, 0}), velocity({0, 0})
{
    this->game = game;
    this->sdlRenderer = renderer;
}

GameObject::~GameObject()
{
    for (auto component : this->components)
    {
        delete component.second;
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
}

std::vector<Collision> GameObject::checkCollision(GameObject *object, bool includeTriggers)
{
    std::vector<Collision> collisions;
    for (auto gameCollider : this->colliders)
    {
        if (gameCollider->type == ColliderType::ACTIVE && (!gameCollider->collider->isTrigger || includeTriggers)) {
            auto collisionResult = object->checkCollision(*gameCollider->collider, includeTriggers);
            if (collisionResult.isCollision) {
                collisions.push_back(collisionResult);
            }
        }
    }

    return collisions;
}

Collision GameObject::checkCollision(Collider &collider, bool includeTriggers)
{
    for (auto gameCollider : this->colliders)
    {
        if (!includeTriggers && gameCollider->collider->isTrigger) {
             continue;
        }

        auto thisCollider = gameCollider->collider;
        auto collision = collider.checkCollision(thisCollider);
        if (collision.isCollision) {
            return collision;
        }
    }

    return Collision{ false };
}

void GameObject::handleCollision(Collision collision)
{
    for (auto collisionHandler : this->collisionHandlers)
    {
        collisionHandler->handleCollision(collision);
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
    this->game->gameObjectsWithUpdaters.insert(this);
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
    this->game->gameObjectsWithInputHandlers.insert(this);
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
    if (type == ColliderType::ACTIVE) {
        this->game->gameObjectsReceivingCollisions.insert(this);
    }

    return this;
}

GameObject *GameObject::setGlobalPosition(Vector position)
{
    auto oldPosition = this->globalPosition;
    this->globalPosition = position;
    if (this->game != nullptr && oldPosition.x != position.x) {
        this->game->updatePosition(this);
    }
    return this;
}

Vector GameObject::getGlobalPosition()
{
    return this->globalPosition;
}

double GameObject::getMaxWidth()
{
    return 16;
}
