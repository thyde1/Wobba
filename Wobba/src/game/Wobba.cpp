#include "Wobba.h"
#include "terrain/BackgroundRenderer.h"
#include "terrain/TerrainFactory.h"
#include "terrain/LavaFactory.h"
#include "terrain/FireballFactory.h"
#include "character/CharacterFactory.h"
#include <iostream>

Wobba::Wobba() : Game("Wobba", { 1400, 900 })
{
}

void Wobba::init()
{
    this->instantiateObject()->addRenderer(new BackgroundRenderer());

    auto terrainFactory = TerrainFactory(*this);
    auto lavaFactory = LavaFactory(*this);
    auto fireballFactory = FireballFactory(*this);
    for (double x = 0; x < 60000; x += 100) {
        auto random = rand() % 10;
        if (x < 200 || random > 7) {
            terrainFactory.create({ x, 800 });
        }

        if (x >= 200 && random == 0) {
            fireballFactory.create({ x + 25, 1000 });
        }

        if (x >= 200 && random <= 7) {
            lavaFactory.create({ x, 850 });
        }

        for (double y = 500; y <= 700; y += 100) {
            if (x > 200 && rand() % 10 < 3) {
                terrainFactory.create({ x, y });
            }
        }
    }

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
