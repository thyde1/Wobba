#pragma once

#include "../Direction.h"

class CharacterInfo : public Component {
public:
    Size size = { 100, 100 };
    bool isGrounded = false;
    Direction direction = Direction::NONE;
    bool jumping = false;
    bool jumpHeld = false;
    bool alive = true;
};
