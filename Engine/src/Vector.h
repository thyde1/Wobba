#pragma once

#include <cmath>

template <class T>
struct GVector {
    double x, y;

    GVector<T> operator+(const GVector<T> &rhs)
    {
        return { this->x + rhs.x, this->y + rhs.y };
    };

    GVector<T> operator-(const GVector<T> &rhs)
    {
        return { this->x - rhs.x, this->y - rhs.y };
    };

    GVector<T> operator+=(const GVector<T> &rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    GVector<T> operator*(const T &rhs)
    {
        return { this->x * rhs, this->y * rhs };
    }

    GVector<T> operator/(const T &rhs)
    {
        return { this->x / rhs, this->y / rhs };
    }

    bool operator==(const GVector<T> &rhs)
    {
        return this->x == rhs.x && this->y == rhs.y;
    }

    T magnitude() {
        return std::hypot(this->x, this->y);
    };

    T magnitudeSquared()
    {
        return std::pow(this->x, 2) + std::pow(this->y, 2);
    };

    GVector<T> normalize()
    {
        return *this / this->magnitude();
    };
};

using Vector = GVector<double>;
