#pragma once

#include "Component.h"
#include "SDL_mixer.h"

class SoundPlayer : public Component {
public:
    SoundPlayer(const char *wavFile);
    ~SoundPlayer();
    void play();
private:
    Mix_Chunk *wav;
};
