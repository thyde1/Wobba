#include "GoalFactory.h"
#include "WinCollisionHandler.h"

GoalFactory::GoalFactory(Game &game) : game(game)
{
}

GameObject *GoalFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position - Vector{ 0, 10 })
        ->addRenderer(new SpriteRenderer("assets/goal.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider({ 14, 20 }, { 0, 0 }, true))
        ->addCollisionHandler(new WinCollisionHandler());
}
