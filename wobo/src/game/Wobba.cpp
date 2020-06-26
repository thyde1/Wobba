#include "Wobba.h"
#include "terrain/TerrainFactory.h"
#include "character/CharacterFactory.h"
#include <iostream>

Wobba::Wobba() : Game("Wobba", { 1400, 900 })
{
}

void Wobba::init()
{
    auto terrainFactory = TerrainFactory(*this);
    for (double x = 0; x < 60000; x += 100) {
        if (x < 200 || rand() % 10 < 4) {
            terrainFactory.create({ x, 800 });
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
