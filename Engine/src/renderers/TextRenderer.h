#pragma once

#include <vector>
#include "SDL_ttf.h"
#include "../Renderer.h"
#include "../Position.h"
#include "Text/TextAlignment.h"

class TextRenderer : public Renderer {
public:
    TextRenderer();
    TextRenderer(SDL_Color color);
    TextRenderer(SDL_Color color, TextAlignment alignment);
    TextRenderer(SDL_Color color, TextAlignment alignment, std::vector<const char *>text);
    ~TextRenderer();
    virtual void render();
    std::vector<const char*> text;
private:
    int width;
    TextAlignment alignment;
    TTF_Font *font;
    SDL_Color color;
};
