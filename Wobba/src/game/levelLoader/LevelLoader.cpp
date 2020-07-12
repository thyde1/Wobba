#include "LevelLoader.h"
#include <fstream>
#include <iostream>

LevelLoader::LevelLoader(Game &game)
    : game(game), terrainFactory(TerrainFactory(game)), lavaFactory(LavaFactory(game)), fireballFactory(FireballFactory(fireballFactory)), creepyFactory(CreepyFactory(game))
{
}

namespace {

    void loadDocument(const char *file, rapidxml::xml_document<> *document, std::string &contentsString)
    {
        std::ifstream fileStream(file);
        std::string fileLine;
        while (std::getline(fileStream, fileLine)) {
            contentsString.append(fileLine);
        }

        document->parse<rapidxml::parse_default>(&contentsString.front());
    }

    GVector<int> getTileSizes(rapidxml::xml_document<> *document)
    {
        auto tileset = document->first_node("map")->first_node("tileset");
        auto tileWidth = std::atoi(tileset->first_attribute("tilewidth")->value());
        auto tileHeight = std::atoi(tileset->first_attribute("tileheight")->value());
        return { tileWidth, tileHeight };
    }

    GVector<int> getMapSize(rapidxml::xml_document<> *document)
    {
        auto mapNode = document->first_node("map");
        return { std::atoi(mapNode->first_attribute("width")->value()), std::atoi(mapNode->first_attribute("height")->value()) };
    }
}

void LevelLoader::load(const char *file)
{
    rapidxml::xml_document<> *document = new rapidxml::xml_document<>();
    std::string contentsString;
    loadDocument(file, document, contentsString);
    auto tileSizes = getTileSizes(document);
    auto mapSize = getMapSize(document);
    auto objectIndexFactories = this->getObjectIndexFactories(document);

    delete document;
}


std::map<std::string, GameObjectFactory> LevelLoader::getObjectIndexFactories(rapidxml::xml_document<> *document)
{
    const char *terrainNodeName = "terrain";
    auto tileset = document->first_node("map")->first_node("tileset");
    std::map<std::string, GameObjectFactory> objectFactories = {
        { "Terrain", this->terrainFactory },
        { "Lava", this->lavaFactory }
    };
    std::map<std::string, GameObjectFactory> objectIndexFactories;

    auto terrainTypes = tileset->first_node("terraintypes");
    auto terrainType = terrainTypes->first_node("terrain");
    while (terrainType) {
        std::cout << terrainType->first_attribute("name")->value();
        objectIndexFactories[terrainType->first_attribute("tile")->value()] = objectFactories[terrainType->first_attribute("name")->value()];
        terrainType = terrainType->next_sibling(terrainNodeName);
    };
    return objectIndexFactories;
}
