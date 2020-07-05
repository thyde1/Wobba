#include "TextRenderer.h"
#include <string>
#include <vector>
#include "../GameObject.h"

TextRenderer::TextRenderer(SDL_Color color, TextAlignment alignment, std::vector<const char *> text)
    : color(color), font(TTF_OpenFont("assets/verdana.ttf", 10)), width(400), alignment(alignment), text(text)
{
}

TextRenderer::TextRenderer(SDL_Color color, TextAlignment alignment) : TextRenderer(color, alignment, std::vector<const char*>())
{
}

TextRenderer::TextRenderer(SDL_Color color) : TextRenderer(color, TextAlignment::LEFT)
{
}


TextRenderer::TextRenderer() : TextRenderer({ 0, 0, 0, 255 })
{
}

TextRenderer::~TextRenderer()
{
    TTF_CloseFont(this->font);
}

void TextRenderer::render()
{
    std::vector<SDL_Texture *> textures;
    for (auto line : this->text) {
        auto textSurface = TTF_RenderText_Solid(this->font, line, this->color);
        auto textTexture = SDL_CreateTextureFromSurface(this->sdlRenderer, textSurface);
        SDL_FreeSurface(textSurface);
        textures.push_back(textTexture);
    }

    int currentYOffset = 0;
    for (auto texture : textures) {
        int w, h;
        SDL_QueryTexture(texture, NULL, NULL, &w, &h);
        SDL_Rect uiRect{ (int)this->gameObject->getGlobalPosition().x, (int)(this->gameObject->getGlobalPosition().y + currentYOffset), w, h };
        switch (this->alignment) {
        case TextAlignment::LEFT:
            break;
        case TextAlignment::CENTER:
            uiRect.x = (int)(this->gameObject->getGlobalPosition().x - w / 2);
            break;
        }
        currentYOffset += h;
        SDL_RenderCopy(this->sdlRenderer, texture, NULL, &uiRect);
        SDL_DestroyTexture(texture);
    }
}
