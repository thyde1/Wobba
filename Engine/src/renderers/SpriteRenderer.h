#pragma once
#include "../Renderer.h"
class SpriteRenderer : public Renderer
{
public:
    SpriteRenderer(const char *imagePath);
    ~SpriteRenderer();
    void render();
    void render(const double rotation);
private:
    const char *imagePath;
    SDL_Texture *texture;
    int w, h;
    SDL_Rect textureRect;
    SDL_Point center;
};
