#include "DeadCreepyFactory.h"
#include "../components/SetLifespanUpdater.h"

DeadCreepyFactory::DeadCreepyFactory(Game &game) : game(game)
{
}

GameObject *DeadCreepyFactory::Create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new AnimatedSpriteRenderer("assets/deadCreepy.png", { 8, 8 }, { 8, 8 }, 4))
        ->addUpdater(new SetLifespanUpdater(200));
}
