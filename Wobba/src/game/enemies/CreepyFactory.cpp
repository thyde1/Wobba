#include "CreepyFactory.h"
#include "CreepyUpdater.h"
#include "CreepyRenderer.h"
#include "../components/Damager.h"
#include "../components/DamageTaker.h"

CreepyFactory::CreepyFactory(Game &game, CreepyColor creepyColor) : game(game), creepyColor(creepyColor)
{
}

GameObject *CreepyFactory::create(Vector position)
{
    auto creepyInfo = new CreepyInfo(this->creepyColor);
    return this->game.instantiateObject()
        ->addComponent(creepyInfo)
        ->addUpdater(new CreepyUpdater(*creepyInfo, (int)position.x, 10))
        ->addRenderer(new CreepyRenderer(*creepyInfo))
        ->addCollider(ColliderType::PASSIVE, new Collider({ 8, 4 }, { 0, 4 }, true))
        ->addComponent(new Damager())
        ->addComponent(new DamageTaker(1))
        ->setGlobalPosition(position + Vector{ 2, 2 });
}
