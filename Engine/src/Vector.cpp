#include "Vector.h"
#include <cmath>

double Vector::magnitude()
{
    return std::hypot(this->x, this->y);
}

double Vector::magnitudeSquared()
{
    return std::pow(this->x, 2) + std::pow(this->y, 2);
}

Vector Vector::normalize()
{
    return *this / this->magnitude();
}
