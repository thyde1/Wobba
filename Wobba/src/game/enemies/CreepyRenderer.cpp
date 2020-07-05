#include "CreepyRenderer.h"

CreepyRenderer::CreepyRenderer(CreepyInfo &creepyInfo)
    : AnimatedSpriteRenderer(getSprite(creepyInfo.color), { 8, 8 }, { 8, 8 }), creepyInfo(creepyInfo)
{
}

Animation CreepyRenderer::getAnimation()
{
    return this->creepyInfo.direction == Direction::RIGHT ? walkingRight : walkingLeft;
}

const char *CreepyRenderer::getSprite(CreepyColor color)
{
    switch (color) {
    case CreepyColor::green:
        return "assets/creepy.png";
    case CreepyColor::blue:
        return "assets/blueCreepy.png";
    default:
        return "assets/creepy.png";
    }
}
