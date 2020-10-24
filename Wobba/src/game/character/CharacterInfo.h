#pragma once

#include "../Direction.h"

class CharacterInfo : public Component {
public:
    Size size = { 8, 8 };
    bool isGrounded = false;
    Direction currentMovementDirection = Direction::NONE;
    Direction lastMovementDirection = Direction::RIGHT;
    bool jumping = false;
    bool jumpHeld = false;
    bool attacking = false;
    int attackDuration = 0;
    bool alive = true;
};
