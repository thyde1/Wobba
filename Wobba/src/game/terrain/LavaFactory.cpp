#include "LavaFactory.h"
#include "Damager.h"

LavaFactory::LavaFactory(Game &game) : game(game)
{
}

GameObject *LavaFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new SpriteRenderer("assets/Lava.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 100, 100 }))
        ->addComponent(new Damager());
}
