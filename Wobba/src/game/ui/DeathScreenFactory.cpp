#include "DeathScreenFactory.h"
#include "DeadRenderer.h"
#include "DeathUpdater.h"

DeathScreenFactory::DeathScreenFactory(Game &game) : game(game)
{
}

GameObject *DeathScreenFactory::create()
{
    auto deathSoundPlayer = new SoundPlayer("assets/Death.wav");
    auto deathTextRenderer = new TextRenderer(SDL_Color{ 0, 0, 0, 255 }, TextAlignment::CENTER, std::vector<const char *>{"YOU ARE DEAD"});
    auto gameObject = this->game.instantiateObject()
        ->addComponent(deathSoundPlayer)
        ->addUpdater(new DeathUpdater(deathTextRenderer))
        ->addRenderer(new DeadRenderer())
        ->addRenderer(deathTextRenderer)
        ->setGlobalPosition({ (double)(this->game.windowSize.w / 20), (double)(this->game.windowSize.h / 20) - 10 });
    deathSoundPlayer->play();
    return gameObject;

}
