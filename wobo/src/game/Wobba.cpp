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
    terrainFactory.create({ 700, 500 });
    terrainFactory.create({ 800, 500 });
    terrainFactory.create({ 100, 500 });
    terrainFactory.create({ 200, 400 });
    terrainFactory.create({ 200, 300 });
    terrainFactory.create({ 200, 200 });
    terrainFactory.create({ 500, 300 });

    auto characterFactory = CharacterFactory(*this);
    characterFactory.create()->setGlobalPosition({ 50, 400 });
}
