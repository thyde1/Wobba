#include "LevelLoader.h"
#include <string>
#include <vector>
#include <fstream>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>

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

    std::vector<Uint32> decodeBase64(std::string input)
    {
        typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<boost::archive::iterators::remove_whitespace
            <std::string::const_iterator>>, 8, 6> ItBinaryT;

        size_t num_pad_chars((4 - input.size() % 4) % 4);
        input.append(num_pad_chars, '=');

        size_t pad_chars(std::count(input.begin(), input.end(), '='));
        std::replace(input.begin(), input.end(), '=', 'A');
        std::string output(ItBinaryT(input.begin()), ItBinaryT(input.end()));
        output.erase(output.end() - pad_chars, output.end());

        Uint32 *out = (Uint32 *)malloc(output.size());
        memcpy(out, output.c_str(), output.size());
        std::vector<Uint32> vectorResult(output.size() / 4);
        vectorResult.assign(out, out + output.size() / 4);
        return vectorResult;
    }
}

void LevelLoader::load(const char *file)
{
    rapidxml::xml_document<> *document = new rapidxml::xml_document<>();
    std::string contentsString;
    loadDocument(file, document, contentsString);
    auto tileSize = getTileSizes(document);
    auto mapSize = getMapSize(document);
    auto objectIndexFactories = this->getObjectIndexFactories(document);

    std::string data = document->first_node("map")->first_node("layer")->first_node("data")->value();

    auto decoded = decodeBase64(data);

    Uint32 tileNumber = 0;
    for (int row = 0; row < mapSize.y; row++) {
        for (int column = 0; column < mapSize.x; column++) {
            if (tileNumber >= decoded.size()) {
                break;
            }
            auto tileGid = decoded[tileNumber];
            if (tileGid != 0) {
                objectIndexFactories[tileGid]->create({ (double)column * tileSize.x, (double)row * tileSize.y });
            }

            tileNumber++;
        }
    }

    delete document;
}

std::map<Uint32, GameObjectFactory*> LevelLoader::getObjectIndexFactories(rapidxml::xml_document<> *document)
{
    const char *terrainNodeName = "terrain";
    auto tileset = document->first_node("map")->first_node("tileset");
    int firstGid = std::stoi(document->first_node("map")->first_node("tileset")->first_attribute("firstgid")->value());
    std::map<std::string, GameObjectFactory*> objectFactories = {
        { "Terrain", &this->terrainFactory },
        { "Lava", &this->lavaFactory }
    };

    std::map<Uint32, GameObjectFactory*> objectIndexFactories;

    auto terrainTypes = tileset->first_node("terraintypes");
    auto terrainType = terrainTypes->first_node("terrain");
    while (terrainType) {
        auto tileGid = std::stoi(terrainType->first_attribute("tile")->value()) + firstGid;
        objectIndexFactories[tileGid] = objectFactories[terrainType->first_attribute("name")->value()];
        terrainType = terrainType->next_sibling(terrainNodeName);
    };
    return objectIndexFactories;
}
