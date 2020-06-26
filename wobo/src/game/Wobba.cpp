#include "Wobba.h"
#include "terrain/TerrainFactory.h"
#include "character/CharacterFactory.h"

Wobba::Wobba() : Game("Wobba", { 1400, 900 })
{
}

void Wobba::init()
{
    auto terrainFactory = TerrainFactory(*this);
    for (double x = 0; x < 2400; x += 100) {
        terrainFactory.create({ x, 500 });
    }

    terrainFactory.create({ 100, 500 });
    terrainFactory.create({ 200, 400 });
    terrainFactory.create({ 200, 300 });
    terrainFactory.create({ 200, 200 });
    terrainFactory.create({ 500, 300 });

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
