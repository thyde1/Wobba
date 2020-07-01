#include "Wobba.h"
#include <iostream>
#include "terrain/BackgroundRenderer.h"
#include "terrain/TerrainFactory.h"
#include "terrain/LavaFactory.h"
#include "terrain/FireballFactory.h"
#include "character/CharacterFactory.h"

Wobba::Wobba() : Game("Wobba", { 1400, 900 })
{
}

void Wobba::init()
{
    SDL_RenderSetScale(this->renderer, 10, 10);
    this->instantiateObject()
        ->addRenderer(new BackgroundRenderer())
        ->addComponent(new MusicPlayer("assets/CreepOut.xm"));

    auto terrainFactory = TerrainFactory(*this);
    auto lavaFactory = LavaFactory(*this);
    auto fireballFactory = FireballFactory(*this);
    for (double x = 0; x < 6000; x += 10) {
        auto random = rand() % 10;
        if (x < 20 || random > 7) {
            terrainFactory.create({ x, 80 });
        }

        if (x >= 20 && random == 0) {
            fireballFactory.create({ x + 2.5, 100 });
        }

        if (x >= 20 && random <= 7) {
            lavaFactory.create({ x, 85 });
        }

        for (double y = 50; y <= 70; y += 10) {
            if (x > 20 && rand() % 10 < 3) {
                terrainFactory.create({ x, y });
            }
        }
    }

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 5, 40 });
}
