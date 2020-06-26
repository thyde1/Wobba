#include "DeadInputHandler.h"

void DeadInputHandler::handleInput(std::list<SDL_Keysym> keys)
{
    for (auto key : keys) {
        if (key.sym == SDLK_SPACE) {
            this->gameObject->game->reset();
        }
    }
}
