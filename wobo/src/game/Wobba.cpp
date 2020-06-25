#include "Wobba.h"
#include "terrain/TerrainFactory.h"
#include "character/CharacterFactory.h"

Wobba::Wobba() : Game("Wobba", { 800, 600 })
{
}

void Wobba::init()
{
    auto terrainFactory = TerrainFactory(*this);
    terrainFactory.create({ 0, 500 });
    terrainFactory.create({ 100, 500 });
    terrainFactory.create({ 200, 500 });
    terrainFactory.create({ 300, 500 });
    terrainFactory.create({ 400, 500 });
    terrainFactory.create({ 500, 500 });
    terrainFactory.create({ 600, 500 });
    terrainFactory.create({ 100, 500 });
    terrainFactory.create({ 200, 400 });
    terrainFactory.create({ 200, 300 });
    terrainFactory.create({ 200, 200 });
    for (float x = 0; x + 8 <= 800; x += 8) {
    }

    for (float y = 400; y < 500; y += 8) {
    }

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
