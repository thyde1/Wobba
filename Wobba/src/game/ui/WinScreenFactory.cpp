#include "WinScreenFactory.h"
#include "ClearScreenRenderer.h"

WinScreenFactory::WinScreenFactory(Game &game) : game(game)
{
}

GameObject *WinScreenFactory::create()
{
    auto winSoundPlayer = new SoundPlayer("assets/Win.wav");

    auto gameObject = this->game.instantiateObject()
        ->setGlobalPosition({ (double)(this->game.windowSize.w / 20), (double)(this->game.windowSize.h / 20) - 10 })
        ->addRenderer(new ClearScreenRenderer(SDL_Color{ 255, 255, 255, 255 }))
        ->addRenderer(new TextRenderer(SDL_Color{ 0, 0, 0, 255 }, TextAlignment::CENTER, std::vector<const char *>{"YOU WIN"}))
        ->addComponent(winSoundPlayer);

    winSoundPlayer->play();
    return gameObject;
}
