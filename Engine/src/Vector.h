#pragma once

struct Vector {
    double x, y;

    Vector operator+(const Vector &rhs)
    {
        return { this->x + rhs.x, this->y + rhs.y };
    };

    Vector operator-(const Vector &rhs)
    {
        return { this->x - rhs.x, this->y - rhs.y };
    };

    Vector operator+=(const Vector &rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector operator*(const double &rhs)
    {
        return { this->x * rhs, this->y * rhs };
    }

    Vector operator/(const double &rhs)
    {
        return { this->x / rhs, this->y / rhs };
    }

    bool operator==(const Vector &rhs)
    {
        return this->x == rhs.x && this->y == rhs.y;
    }

    double magnitude();

    double magnitudeSquared();

    Vector normalize();
};
