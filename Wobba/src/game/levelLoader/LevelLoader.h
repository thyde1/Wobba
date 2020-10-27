#pragma once
#include <map>
#include <rapidxml/rapidxml.hpp>
#include "Engine.h"
#include "GameObjectFactory.h"

class LevelLoader {
public:
    LevelLoader(Game &game);
    void load(const char *file);
private:
    Game &game;
    std::map<Uint32, GameObjectFactory*> getObjectIndexFactories(rapidxml::xml_document<> *document);
};
