#include "DamagedSoundPlayer.h"

DamagedSoundPlayer::DamagedSoundPlayer(const char *file) : soundPlayer(SoundPlayer(file))
{
}

void DamagedSoundPlayer::play()
{
    this->soundPlayer.setGameObject(this->getGameObject());
    this->soundPlayer.play();
}
