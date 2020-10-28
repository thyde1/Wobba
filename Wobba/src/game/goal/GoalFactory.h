#pragma once

#include "../levelLoader/GameObjectFactory.h"

class GoalFactory : public GameObjectFactory {
public:
    GoalFactory(Game &game);
    GameObject *create(Vector position) override;
private:
    Game &game;
};
