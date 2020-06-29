#include "LavaFactory.h"
#include "Damager.h"

LavaFactory::LavaFactory(Game &game) : game(game)
{
}

GameObject *LavaFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new AnimatedSpriteRenderer("assets/lava.png", { 8, 8 }, { 10, 10 }, 8))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 10, 10 }))
        ->addComponent(new Damager());
}
