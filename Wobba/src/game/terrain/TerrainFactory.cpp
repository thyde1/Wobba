#include "TerrainFactory.h"

TerrainFactory::TerrainFactory(Game &game) : game(game)
{
}

GameObject* TerrainFactory::create(Vector position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new SpriteRenderer("assets/terrain2.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 100, 100 }));
}
