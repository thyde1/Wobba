#include "Wobba.h"
#include <iostream>
#include "terrain/BackgroundRenderer.h"
#include "terrain/TerrainFactory.h"
#include "terrain/LavaFactory.h"
#include "hazards/FireballFactory.h"
#include "enemies/CreepyFactory.h"
#include "character/CharacterFactory.h"
#include "../game/levelLoader/LevelLoader.h"

Wobba::Wobba() : Game("Wobba", { 1400, 900 }, 10)
{
}

void Wobba::init()
{
    SDL_RenderSetScale(this->renderer, 10, 10);
    this->instantiateObject()
        ->addRenderer(new BackgroundRenderer())
        ->addComponent(new MusicPlayer("assets/CreepOut.xm"));

    LevelLoader levelLoader(*this);
    levelLoader.load("resources/maps/LavaCaveLevel.tmx");

    auto terrainFactory = TerrainFactory(*this);
    auto lavaFactory = LavaFactory(*this);
    auto fireballFactory = FireballFactory(*this);
    auto creepyFactory = CreepyFactory(*this);

    auto createCreepyOnPlatform = [&](double x, double y) {
        terrainFactory.create({ x, y });
        terrainFactory.create({ x + 10, y });
        terrainFactory.create({ x + 20, y });
        creepyFactory.create({ x + 10, y - 8 }, rand() % 2 == 0 ? CreepyColor::blue : CreepyColor::green);
    };

    double lastCreepy = 0;
    for (double x = 0; x < 6000; x += 10) {
        auto random = rand() % 100;
        if (x < 20 || random > 70) {
            terrainFactory.create({ x, 80 });
        }

        if (x >= 20 && random < 5) {
            fireballFactory.create({ x + 2.5, 100 });
        }

        if (x >= 20 && random <= 70) {
            lavaFactory.create({ x, 85 });
        }

        auto blockPlaced = false;
        for (double y = 50; y <= 70; y += 10) {
            if (lastCreepy >= x - 30) {
                break;
            }

            if (!blockPlaced && x >= 30 && rand() % 100 < 10) {
                createCreepyOnPlatform(x, y);
                lastCreepy = x;
                break;
            }

            if (x > 20 && rand() % 10 < 3) {
                terrainFactory.create({ x, y });
                blockPlaced = true;
            }
        }
    }

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 5, 40 });
}
