#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(const char *wavFile)
{
    this->wav = Mix_LoadWAV(wavFile);
}

SoundPlayer::~SoundPlayer()
{
    Mix_FreeChunk(this->wav);
}

void SoundPlayer::play()
{
    Mix_PlayChannel(-1, this->wav, 0);
}
