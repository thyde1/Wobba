#include "CharacterFactory.h"
#include "CharacterUpdater.h"
#include "CharacterInfo.h"
#include "CharacterCollisionHandler.h"
#include "CharacterInputHandler.h"

CharacterFactory::CharacterFactory(Game &game) : game(game)
{
}

GameObject *CharacterFactory::create()
{
    auto characterInfo = new CharacterInfo;

    return this->game.instantiateObject()
        ->setGlobalPosition({ 15, 15 })
        ->addComponent(characterInfo)
        ->addRenderer(new SpriteRenderer("assets/character.png"))
        ->addCollider(ColliderType::ACTIVE, new Collider(Size{8, 9}))
        ->addUpdater(new CharacterUpdater(*characterInfo))
        ->addCollisionHandler(new CharacterCollisionHandler(*characterInfo))
        ->addInputHandler(new CharacterInputHandler(*characterInfo));
}
