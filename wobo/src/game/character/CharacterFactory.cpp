#include "CharacterFactory.h"
#include "CharacterUpdater.h"
#include "CameraUpdater.h"
#include "CharacterInfo.h"
#include "CharacterCollisionHandler.h"
#include "CharacterInputHandler.h"

CharacterFactory::CharacterFactory(Game &game) : game(game)
{
}

GameObject *CharacterFactory::create()
{
    auto characterInfo = new CharacterInfo;
    auto groundCollider = new Collider(Size{ 100, 1 }, { 0, 100 });

    return this->game.instantiateObject()
        ->setGlobalPosition({ 15, 15 })
        ->addComponent(characterInfo)
        ->addRenderer(new SpriteRenderer("assets/character2.png"))
        ->addCollider(ColliderType::ACTIVE, new Collider(Size{ 100, 100 }))
        ->addCollider(ColliderType::PASSIVE, groundCollider)
        ->addUpdater(new CharacterUpdater(*characterInfo, *groundCollider))
        ->addUpdater(new CameraUpdater())
        ->addCollisionHandler(new CharacterCollisionHandler(*characterInfo))
        ->addInputHandler(new CharacterInputHandler(*characterInfo));
}
