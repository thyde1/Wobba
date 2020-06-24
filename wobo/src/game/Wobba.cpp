#include "Wobba.h"
#include "terrain/TerrainFactory.h"
#include "character/CharacterFactory.h"

Wobba::Wobba() : Game("Wobba", { 800, 600 })
{
}

void Wobba::init()
{
    auto terrainFactory = TerrainFactory(*this);
    for (float x = 0; x + 8 <= 800; x += 8) {
        terrainFactory.create({ x, 500 });
    }

    for (float y = 400; y < 500; y += 8) {
        terrainFactory.create({ 500, y });
    }

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
