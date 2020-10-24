#pragma once

#include "Engine.h"
#include "SDL_mixer.h"

class SoundPlayer : public Component {
public:
    SoundPlayer(const char *wavFile);
    void play();
private:
    const char *wavFile;
    int currentChannel = -1;
};
