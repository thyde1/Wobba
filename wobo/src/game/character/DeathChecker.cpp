#include "DeathChecker.h"
#include "DeadRenderer.h"

void DeathChecker::update(int elapsed)
{
    if (this->gameObject->globalPosition.y > 1000) {
        this->gameObject->game->instantiateObject()
            ->addRenderer(new DeadRenderer())
            ->addRenderer(new TextRenderer(SDL_Color{ 0, 0, 0, 255 }, TextAlignment::CENTER, std::vector<const char *>{"YOU ARE DEAD"}))
            ->setGlobalPosition({ (double)(this->gameObject->game->windowSize.w / 2), (double)(this->gameObject->game->windowSize.h / 2 )});
    }
}
