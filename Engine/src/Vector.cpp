#include "Vector.h"
#include <cmath>

Vector Vector::normalize()
{
    double magnitude = std::hypot(this->x, this->y);
    return *this / magnitude;
}
