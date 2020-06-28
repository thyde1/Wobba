#include "FireballFactory.h"
#include "Damager.h"
#include "FireballUpdater.h"

FireballFactory::FireballFactory(Game &game) : game(game)
{
}

GameObject *FireballFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new SpriteRenderer("assets/fireball.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 50, 50 }))
        ->addComponent(new Damager())
        ->addUpdater(new FireballUpdater());
}
