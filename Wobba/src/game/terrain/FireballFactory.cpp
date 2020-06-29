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
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 5, 5 }, { 0, 0 }, true))
        ->addComponent(new Damager())
        ->addUpdater(new FireballUpdater(position.x, (rand() % 10) * 0.1));
}
