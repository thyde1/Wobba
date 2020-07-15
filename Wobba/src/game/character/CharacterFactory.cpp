#include "CharacterFactory.h"
#include "CharacterUpdater.h"
#include "CameraUpdater.h"
#include "DeathChecker.h"
#include "CharacterInfo.h"
#include "CharacterCollisionHandler.h"
#include "CharacterInputHandler.h"
#include "CharacterRenderer.h"
#include "SwordRenderer.h"
#include "SwordCollider.h"

CharacterFactory::CharacterFactory(Game &game) : game(game)
{
}

GameObject *CharacterFactory::create()
{
    auto characterInfo = new CharacterInfo;
    auto groundCollider = new Collider(Size{ characterInfo->size.w, 1 }, { 0, (double)characterInfo->size.h });
    Collider *swordCollider = new SwordCollider(*characterInfo);
    auto jumpSoundPlayer = new SoundPlayer("assets/Jump.wav");

    return this->game.instantiateObject()
        ->setGlobalPosition({ 15, 15 })
        ->addComponent(characterInfo)
        ->addComponent(groundCollider)
        ->addComponent(jumpSoundPlayer)
        ->addRenderer(new CharacterRenderer(characterInfo))
        ->addRenderer(new SwordRenderer(*characterInfo))
        ->addCollider(ColliderType::ACTIVE, new Collider(characterInfo->size))
        ->addCollider(ColliderType::ACTIVE, swordCollider)
        ->addCollider(ColliderType::PASSIVE, groundCollider)
        ->addUpdater(new CharacterUpdater(*characterInfo, *groundCollider, *jumpSoundPlayer))
        ->addUpdater(new CameraUpdater())
        ->addUpdater(new DeathChecker())
        ->addCollisionHandler(new CharacterCollisionHandler(*characterInfo, *swordCollider))
        ->addInputHandler(new CharacterInputHandler(*characterInfo));
}
