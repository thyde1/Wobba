#include "DeathUpdater.h"
#include "DeadInputHandler.h"

DeathUpdater::DeathUpdater(TextRenderer *deathTextRenderer) : deathTextRenderer(deathTextRenderer)
{
}

void DeathUpdater::update(int elapsed)
{
    const int millisecondsBeforeRestartAllowed = 500;

    if (millisecondsSinceDeath >= millisecondsBeforeRestartAllowed) {
        return;
    }

    if (millisecondsSinceDeath < millisecondsBeforeRestartAllowed) {
        this->millisecondsSinceDeath += elapsed;
    }

    if (millisecondsSinceDeath < millisecondsBeforeRestartAllowed) {
        return;
    }

    this->deathTextRenderer->text.push_back("Press space to try again");
    this->gameObject->addInputHandler(new DeadInputHandler());
}
