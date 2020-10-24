#include "CreepyFactory.h"
#include "CreepyUpdater.h"
#include "CreepyRenderer.h"
#include "../components/Damager.h"
#include "../components/DamageTaker.h"
#include "../components/DamagedSoundPlayer.h"

CreepyFactory::CreepyFactory(Game &game, CreepyColor creepyColor) : game(game), creepyColor(creepyColor)
{
}

GameObject *CreepyFactory::create(Vector position)
{
    auto creepyInfo = new CreepyInfo(this->creepyColor);
    auto damagedSoundPlayer = new DamagedSoundPlayer("assets/CreepyDeath.wav");
    return this->game.instantiateObject()
        ->addComponent(creepyInfo)
        ->addUpdater(new CreepyUpdater(*creepyInfo, (int)position.x, 10))
        ->addRenderer(new CreepyRenderer(*creepyInfo))
        ->addCollider(ColliderType::PASSIVE, new Collider({ 8, 4 }, { 0, 4 }, true))
        ->addComponent(new Damager())
        ->addComponent(damagedSoundPlayer)
        ->addComponent(new DamageTaker(1, *damagedSoundPlayer))
        ->setGlobalPosition(position + Vector{ 2, 2 });
}
