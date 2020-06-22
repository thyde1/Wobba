#pragma once

#include "../Direction.h"

class CharacterInfo : public Component {
public:
    Size size = { 8, 8 };
    bool isGrounded = false;
    Direction direction = Direction::NONE;
    bool jumping = false;
    Vector velocity = { 0, 0 };
};
