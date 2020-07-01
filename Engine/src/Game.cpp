#include <memory>
#include <cmath>
#include <iostream>
#include "Game.h"
#include "SDL_mixer.h"
#include "TextureManager.h"
#include "Collider.h"

Game::Game(const char *title, Size windowSize) : windowSize(windowSize), title(title), isRunning(true), cameraPosition({ 0, 0 }), gameObjectsByLocation(ObjectBucket(100))
{
    this->sdlInit();
    this->textureManager = TextureManager(this->renderer);
}

Game::~Game()
{
}

void Game::sdlInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MOD);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 64);

    SDL_Window* window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowSize.w, this->windowSize.h, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, 0);

    this->clearScreen();

    SDL_RenderPresent(renderer);

    this->gameObjects = *new std::list<GameObject*>();
}

void Game::start()
{
    this->init();
    const int fps = 144;
    const int frameDelay = 1000 / fps;

    auto frameStart = SDL_GetTicks();
    auto lastUpdate = SDL_GetTicks();
    while (this->isRunning) {
        this->instantiateGameObjectsPendingInstantiation();
        auto runningTime = SDL_GetTicks();
        auto elapsed = runningTime - lastUpdate;
        if (elapsed >= 2) {
            this->handleInput();
            this->update(elapsed);
            destroyObjectsPendingDestruction();
            this->applyMovement(elapsed);
            this->checkCollisions();
            destroyObjectsPendingDestruction();
            lastUpdate = SDL_GetTicks();
        }
        if (runningTime - frameStart >= frameDelay) {
            frameStart = runningTime;
            this->render();
        }
    }
    SDL_Quit();
}

void Game::handleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            this->keys.remove_if([&](SDL_Keysym k) { return k.sym == event.key.keysym.sym; });
            this->keys.push_back(event.key.keysym);
            break;
        case SDL_KEYUP:
            this->keys.remove_if([&](SDL_Keysym k) { return k.sym == event.key.keysym.sym; });
            break;
        case SDL_QUIT:
            this->isRunning = false;
            return;
        }
    }

    for (GameObject* gameObject : this->gameObjectsWithInputHandlers)
    {
        gameObject->handleInput(keys);
    }
}

void Game::update(int elapsed)
{
    for(GameObject *gameObject : this->gameObjectsWithUpdaters)
    {
        gameObject->update(elapsed);
    }
}

void Game::applyMovement(int elapsed)
{
    for (GameObject *gameObject : this->gameObjectsWithUpdaters) {
        auto deltaV = gameObject->velocity * elapsed;
        gameObject->globalPosition += deltaV;
    }
}

void Game::checkCollisions(bool includeTriggers)
{
    for (GameObject *gameObject : this->gameObjectsReceivingCollisions)
    {
        std::list<Collision> collisions;
        auto nearbyGameObjects = this->gameObjectsByLocation.get(gameObject->globalPosition);
        for (GameObject *other : nearbyGameObjects) {
            if (other != gameObject) {
                auto collision = gameObject->checkCollision(other, includeTriggers);
                if (collision.isCollision) {
                    collisions.push_front(collision);
                }
            }
        }

        collisions.sort([&](Collision &a, Collision &b) {
            auto collisionADistanceSquared = (a.colliderA->getGameObject()->globalPosition - a.colliderB->getGameObject()->globalPosition).magnitudeSquared();
            auto collisionBDistanceSquared = (b.colliderA->getGameObject()->globalPosition - b.colliderB->getGameObject()->globalPosition).magnitudeSquared();
            if (a.normal.x != 0 && b.normal.x == 0) {
                return true;
            }
            else if (a.normal.x == 0 && b.normal.x != 0) {
                return false;
            }

            return collisionADistanceSquared < collisionBDistanceSquared;
        });

        if (collisions.size() > 0) {
            auto collision = collisions.front();
            collision.colliderA->getGameObject()->handleCollision(collision);
            if (!includeTriggers) {
                this->checkCollisions();
            }
        }
        else if (!includeTriggers) {
            this->checkCollisions(true);
        }
    }
}

std::list<Collision> Game::checkCollisions(Collider collider, bool includeTriggers)
{
    auto nearbyGameObjects = this->gameObjectsByLocation.get(collider.getGameObject()->globalPosition);
    std::list<Collision> collisions;
    for (GameObject *other : nearbyGameObjects) {
        if (other != collider.getGameObject()) {
            auto collision = other->checkCollision(collider, includeTriggers);
            if (collision.isCollision) {
                collisions.push_back(collision);
            }
        }
    }
    return collisions;
}

void Game::render()
{
    this->clearScreen();
    for (GameObject* gameObject : this->gameObjects)
    {
        gameObject->render();
    }

    SDL_RenderPresent(renderer);
}

GameObject* Game::instantiateObject()
{
    auto object = new GameObject(this, this->renderer);
    this->gameObjectsPendingInstantiation.push_back(object);
    return object;
}

void Game::destroyObject(GameObject* object)
{
    this->gameObjectsPendingDestruction.push_back(object);
}

void Game::reset()
{
    for (auto gameObject : this->gameObjects) {
        this->destroyObject(gameObject);
    }

    this->init();
}

void Game::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Game::instantiateGameObjectsPendingInstantiation()
{
    auto createStart = SDL_GetTicks();
    for (auto object : this->gameObjectsPendingInstantiation) {
        this->gameObjects.push_back(object);
        this->gameObjectsByLocation.insert(object);
    }

    if (this->gameObjectsPendingInstantiation.size() > 0) {
        this->gameObjectsPendingInstantiation.clear();
    }
}

void Game::destroyObjectsPendingDestruction()
{
    for (auto object : this->gameObjectsPendingDestruction) {
        this->gameObjects.remove(object);
        this->gameObjectsWithUpdaters.erase(object);
        this->gameObjectsReceivingCollisions.erase(object);
        this->gameObjectsWithInputHandlers.erase(object);
        this->gameObjectsByLocation.remove(object);
        delete object;
    }

    this->gameObjectsPendingDestruction.clear();
}
