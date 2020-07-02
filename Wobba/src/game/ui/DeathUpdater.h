#pragma once

#include <Engine.h>

class DeathUpdater : public Updater {
public:
    DeathUpdater(TextRenderer *deathTextRenderer);
    void update(int elapsed);
private:
    int millisecondsSinceDeath = 0;
    TextRenderer *deathTextRenderer;
};