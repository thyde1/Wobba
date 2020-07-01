#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(const char *modFile) : modFile(modFile)
{
    this->music = Mix_LoadMUS(modFile);
    this->play();
}

MusicPlayer::~MusicPlayer()
{
    Mix_FreeMusic(music);
}

void MusicPlayer::play()
{
    Mix_PlayMusic(music, -1);
}
