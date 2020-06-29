#pragma once

#include "SDL.h"
#include "SDL_TTF.h"
#include <stdio.h>
#include <list>
#include <set>
#include "TextureManager.h"
#include "Size.h"
#include "Vector.h"
#include "ObjectBucket.h"

class Game {
public:
    Game(const char *title, Size windowSize);
    ~Game();
    TextureManager textureManager;
    Size windowSize;
    void sdlInit();
    virtual void init() = 0;
    void start();
    void handleInput();
    void update(int elapsed);
    void applyMovement(int elapsed);
    void checkCollisions(bool includeTriggers = false);
    std::list<Collision> checkCollisions(Collider collider, bool includeTriggers = false);
    void render();
    GameObject* instantiateObject();
    void destroyObject(GameObject* object);
    std::list<GameObject *> gameObjects;
    std::set<GameObject *> gameObjectsWithUpdaters;
    std::set<GameObject *> gameObjectsWithInputHandlers;
    std::set<GameObject *> gameObjectsReceivingCollisions;
    void reset();
    Vector cameraPosition;
protected:
    SDL_Renderer* renderer;
private:
    void clearScreen();
    std::list<GameObject*> gameObjectsPendingInstantiation;
    void instantiateGameObjectsPendingInstantiation();
    std::list<GameObject*> gameObjectsPendingDestruction;
    void destroyObjectsPendingDestruction();
    const char *title;
    bool isRunning;
    std::list<SDL_Keysym> keys;
    ObjectBucket gameObjectsByLocation;
};
