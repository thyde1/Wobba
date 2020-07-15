#include "CharacterInputHandler.h"

CharacterInputHandler::CharacterInputHandler(CharacterInfo &characterInfo) : characterInfo(characterInfo)
{
}

void CharacterInputHandler::handleInput(std::list<SDL_Keysym> keys)
{
    this->characterInfo.direction = Direction::NONE;
    this->characterInfo.jumping = false;
    bool jumpKeyDown = false;
    bool attackKeyDown = false;
    for (auto key : keys) {
        if (key.sym == SDLK_SPACE) {
            jumpKeyDown = true;
        }

        if (key.sym == SDLK_z) {
            attackKeyDown = true;
        }

        if (attackKeyDown && !this->attackHeld) {
            this->characterInfo.attacking = true;
            this->attackHeld = true;
        }

        if (jumpKeyDown && !this->characterInfo.jumpHeld) {
            this->characterInfo.jumping = true;
        }

        if (jumpKeyDown) {
            this->characterInfo.jumpHeld = true;
        }

        switch (key.sym) {
        case SDLK_RIGHT:
            this->characterInfo.direction = Direction::RIGHT;
            break;
        case SDLK_LEFT:
            this->characterInfo.direction = Direction::LEFT;
            break;
        }
    }

    if (!jumpKeyDown) {
        this->characterInfo.jumpHeld = false;
    }

    if (!attackKeyDown) {
        this->attackHeld = false;
    }
}
