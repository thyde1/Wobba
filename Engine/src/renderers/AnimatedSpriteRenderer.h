#pragma once

#include <map>
#include "../Renderer.h"
#include "../Size.h"

struct Animation {
    int startFrame;
    int frameCount;
    bool flippedHorizontal;
};

class AnimatedSpriteRenderer : public Renderer {
public:
    AnimatedSpriteRenderer(const char *imagePath, Size frameSize, Size destSize, std::map<const char *, Animation> animations);
    void render();
private:
    virtual const char *getAnimation() = 0;
    std::map<const char *, Animation> animations;
    Size frameSize;
    int frameCount;
    Size destSize;
    int elapsed = 0;
    int prevFrame = 0;
    int rows;
    int columns;
    const char *imagePath;
    SDL_Texture *texture;
    int w = 0, h = 0;
    SDL_Rect textureRect;
    SDL_Point center;
};
