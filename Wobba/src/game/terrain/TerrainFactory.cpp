#include "TerrainFactory.h"
#include "SafeSurface.h"

TerrainFactory::TerrainFactory(Game &game) : game(game)
{
}

GameObject* TerrainFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new SpriteRenderer("assets/terrain.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 100, 100 }))
        ->addComponent(new SafeSurface());
}
