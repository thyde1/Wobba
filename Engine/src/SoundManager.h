#pragma once

#include <map>
#include <string>

#include "SDL_Mixer.h"

class SoundManager {
public:
	SoundManager()
	{
	}
	Mix_Chunk *getChunk(const char *file);
private:
	int sounds = 0;
	std::map<const char*, Mix_Chunk *> chunks;
};
