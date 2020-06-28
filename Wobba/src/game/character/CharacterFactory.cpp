#include "CharacterFactory.h"
#include "CharacterUpdater.h"
#include "CameraUpdater.h"
#include "DeathChecker.h"
#include "CharacterInfo.h"
#include "CharacterCollisionHandler.h"
#include "CharacterInputHandler.h"

CharacterFactory::CharacterFactory(Game &game) : game(game)
{
}

GameObject *CharacterFactory::create()
{
    auto characterInfo = new CharacterInfo;
    auto groundCollider = new Collider(Size{ 80, 1 }, { 0, 80 });

    return this->game.instantiateObject()
        ->setGlobalPosition({ 15, 15 })
        ->addComponent(characterInfo)
        ->addComponent(groundCollider)
        ->addRenderer(new SpriteRenderer("assets/character.png"))
        ->addCollider(ColliderType::ACTIVE, new Collider(Size{ 80, 80 }))
        ->addCollider(ColliderType::PASSIVE, groundCollider)
        ->addUpdater(new CharacterUpdater(*characterInfo, *groundCollider))
        ->addUpdater(new CameraUpdater())
        ->addUpdater(new DeathChecker())
        ->addCollisionHandler(new CharacterCollisionHandler(*characterInfo))
        ->addInputHandler(new CharacterInputHandler(*characterInfo));
}
