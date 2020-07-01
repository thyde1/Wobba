#pragma once

#include "SDL_mixer.h"
#include "Component.h"

class MusicPlayer : public Component {
public:
    MusicPlayer(const char *modFile);
    ~MusicPlayer();
private:
    const char *modFile;
    Mix_Music *music;
    void play();
};
