#pragma once

#include "../Renderer.h"
#include "../Vector.h"

class SpriteRenderer : public Renderer
{
public:
    enum class Flip {
        HORIZONTAL,
        VERTICAL,
        NONE
    };
    SpriteRenderer(const char *imagePath);
    virtual ~SpriteRenderer();
    void virtual render();
    void render(const double rotation);
    void render(const Flip flip);
    void render(const double rotation, Flip flip);
private:
    virtual GVector<int> getOffset();
    const char *imagePath;
    SDL_Texture *texture;
    int w, h;
    SDL_Rect textureRect;
    SDL_Point center;
};
