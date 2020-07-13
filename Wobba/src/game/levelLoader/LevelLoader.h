#pragma once
#include <map>
#include <rapidxml/rapidxml.hpp>
#include "../terrain/TerrainFactory.h"
#include "../terrain/LavaFactory.h"
#include "../hazards/FireballFactory.h"
#include "../enemies/CreepyFactory.h"

class LevelLoader {
public:
    LevelLoader(Game &game);
    void load(const char *file);
private:
    Game &game;
    TerrainFactory terrainFactory;
    LavaFactory lavaFactory;
    FireballFactory fireballFactory;
    CreepyFactory creepyFactory;
    std::map<Uint32, GameObjectFactory> getObjectIndexFactories(rapidxml::xml_document<> *document);
};
