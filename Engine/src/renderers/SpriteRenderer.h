#pragma once

#include "../Renderer.h"
#include "../Vector.h"

class SpriteRenderer : public Renderer
{
public:
    SpriteRenderer(const char *imagePath);
    virtual ~SpriteRenderer();
    void virtual render();
    void render(const double rotation);
private:
    virtual GVector<int> getOffset();
    const char *imagePath;
    SDL_Texture *texture;
    int w, h;
    SDL_Rect textureRect;
    SDL_Point center;
};
