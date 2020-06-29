#include "DeathChecker.h"
#include "DeadRenderer.h"
#include "DeadInputHandler.h"
#include "CharacterInfo.h"

void DeathChecker::update(int elapsed)
{
    if (this->gameObject->globalPosition.y > 100 || !this->gameObject->getComponent<CharacterInfo>()->alive) {
        this->gameObject->game->instantiateObject()
            ->addRenderer(new DeadRenderer())
            ->addRenderer(new TextRenderer(SDL_Color{ 0, 0, 0, 255 }, TextAlignment::CENTER, std::vector<const char *>{"YOU ARE DEAD", "Press space to try again"}))
            ->addInputHandler(new DeadInputHandler())
            ->setGlobalPosition({ (double)(this->gameObject->game->windowSize.w / 20), (double)(this->gameObject->game->windowSize.h / 20 ) - 10});
        this->gameObject->game->destroyObject(this->gameObject);
    }
}
