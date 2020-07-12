#include "LavaFactory.h"
#include "../components/Damager.h"

LavaFactory::LavaFactory(Game &game) : game(game)
{
}

GameObject *LavaFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new AnimatedSpriteRenderer("assets/lava.png", { 10, 10 }, { 10, 10 }, 8))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 10, 10 }))
        ->addComponent(new Damager());
}
