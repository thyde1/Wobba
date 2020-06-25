#include <memory>
#include <cmath>
#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "Collider.h"

Game::Game(const char *title, Size windowSize) : windowSize(windowSize), title(title), isRunning(true)
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
    SDL_Window* window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowSize.w, this->windowSize.h, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, 0);

    this->clearScreen();

    SDL_RenderPresent(renderer);

    this->gameObjects = *new std::list<GameObject*>();
}

void Game::start()
{
    this->init();
    const int fps = 60;
    const int frameDelay = 1000 / fps;

    auto frameStart = SDL_GetTicks();
    auto lastUpdate = SDL_GetTicks();
    while (this->isRunning) {
        this->instantiateGameObjectsPendingInstantiation();
        auto runningTime = SDL_GetTicks();
        auto elapsed = runningTime - lastUpdate;
        if (elapsed >= 10) {
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

    for (GameObject* gameObject : this->gameObjects)
    {
        
        gameObject->handleInput(keys);
    }
}

void Game::update(int elapsed)
{
    for(GameObject *gameObject : this->gameObjects)
    {
        gameObject->update(elapsed);
    }
}

void Game::applyMovement(int elapsed)
{
    for (GameObject *gameObject : this->gameObjects) {
        auto deltaV = gameObject->velocity * elapsed;
        gameObject->globalPosition += deltaV;
    }
}

void Game::checkCollisions()
{
    for (GameObject *gameObject : this->gameObjects)
    {
        /*std::list<GameObject*> sortedGameObjects = std::list<GameObject*>(gameObjects);
        sortedGameObjects.sort([&](GameObject *a, GameObject *b) {
            return (a->globalPosition - gameObject->globalPosition).magnitudeSquared() > (b->globalPosition - gameObject->globalPosition).magnitudeSquared();
        });*/

        //for (GameObject *other : sortedGameObjects) {
        std::list<Collision> collisions;
        for (GameObject *other : gameObjects) {
            if (other != gameObject) {
                auto collision = gameObject->checkCollision(other);
                if (collision.isCollision) {
                    collisions.push_front(collision);
                }
            }
        }

        collisions.sort([&](Collision &a, Collision &b) {
            auto collisionADistanceSquared = (a.colliderA->getGameObject()->globalPosition - a.colliderB->getGameObject()->globalPosition).magnitudeSquared();
            auto collisionBDistanceSquared = (b.colliderA->getGameObject()->globalPosition - b.colliderB->getGameObject()->globalPosition).magnitudeSquared();
            if (collisionADistanceSquared == collisionBDistanceSquared) {
                return std::abs(a.normal.y) < std::abs(b.normal.y);
            }


            return collisionADistanceSquared < collisionBDistanceSquared;
        });

        for (auto &collision : collisions) {
            if (collision.normal.x != 0.) {
                auto x = 0;
            }
            collision.colliderA->getGameObject()->handleCollision(collision);
        }
    }
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

void Game::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
}

void Game::instantiateGameObjectsPendingInstantiation()
{
    for (auto object : this->gameObjectsPendingInstantiation) {
        this->gameObjects.push_back(object);
    }

    this->gameObjectsPendingInstantiation.clear();
}

void Game::destroyObjectsPendingDestruction()
{
    for (auto object : this->gameObjectsPendingDestruction) {
        this->gameObjects.remove(object);
        delete object;
    }
    this->gameObjectsPendingDestruction.clear();
}
