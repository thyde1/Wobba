#pragma once

struct Position {
    int x, y;
    Position operator+(const Position &rhs)
    {
        return { this->x + rhs.x, this->y + rhs.y };
    };
    Position operator+=(const Position &rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
};
