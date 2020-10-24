#include "SoundManager.h"
#include <iostream>

Mix_Chunk *SoundManager::getChunk(const char *file)
{
    if (this->chunks.count(file) == 0) {
        auto wav = Mix_LoadWAV(file);
        this->chunks[file] = wav;
        sounds++;
        return wav;
    }

    return this->chunks[file];
}
