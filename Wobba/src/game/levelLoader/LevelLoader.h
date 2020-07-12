#pragma once
#include <map>
#include <string>
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
    std::map<std::string, GameObjectFactory> getObjectIndexFactories(rapidxml::xml_document<> *document);
};
