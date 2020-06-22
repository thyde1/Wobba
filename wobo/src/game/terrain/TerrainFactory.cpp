#include "TerrainFactory.h"

TerrainFactory::TerrainFactory(Game &game) : game(game)
{
}

GameObject* TerrainFactory::create(Position position)
{
    return this->game.instantiateObject()
        ->setGlobalPosition(position)
        ->addRenderer(new SpriteRenderer("assets/terrain.png"))
        ->addCollider(ColliderType::PASSIVE, new Collider(Size{ 8, 8 }));
}
