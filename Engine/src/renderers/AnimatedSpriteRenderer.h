#pragma once

#include "../Renderer.h"
#include "../Size.h"

struct Animation {
    int startFrame;
    int frameCount;
    bool flippedHorizontal;
};

class AnimatedSpriteRenderer : public Renderer {
public:
    AnimatedSpriteRenderer(const char *imagePath, Size frameSize, Size destSize);
    void render();
private:
    virtual Animation getAnimation() = 0;
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
