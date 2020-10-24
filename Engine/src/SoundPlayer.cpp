#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(const char *wavFile) : wavFile(wavFile)
{
}

void SoundPlayer::play()
{
    auto gameObject = this->getGameObject();
    auto soundManager = &this->getGameObject()->game->soundManager;
    Mix_PlayChannel(-1, soundManager->getChunk(this->wavFile), 0);
}
