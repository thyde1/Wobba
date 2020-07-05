#include "CreepyInfo.h"

CreepyInfo::CreepyInfo(CreepyColor color) : color(color)
{
    switch (color) {
    case CreepyColor::green:
        this->speed = 0.02;
        break;
    case CreepyColor::blue:
        this->speed = 0.04;
        break;
    default:
        this->speed = 0.02;
        break;
    }
}
