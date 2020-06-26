#include "Wobba.h"
#include "terrain/TerrainFactory.h"
#include "character/CharacterFactory.h"

Wobba::Wobba() : Game("Wobba", { 1400, 900 })
{
}

void Wobba::init()
{
    auto terrainFactory = TerrainFactory(*this);
    for (double x = 0; x < 60000; x += 100) {
        if (x < 200 || rand() % 10 < 8) {
            terrainFactory.create({ x, 800 });
        }
    }

    terrainFactory.create({ 200, 700 });
    terrainFactory.create({ 200, 600 });
    terrainFactory.create({ 200, 500 });
    terrainFactory.create({ 500, 300 });

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
