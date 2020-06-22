#pragma once

struct Vector {
    int x, y;
    Vector operator+(const Vector &rhs)
    {
        return { this->x + rhs.x, this->y + rhs.y };
    };
    Vector operator+=(const Vector &rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
    Vector operator*(const int &rhs)
    {
        return { this->x * rhs, this->y * rhs };
    }
};
