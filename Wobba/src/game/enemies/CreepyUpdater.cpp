#include "CreepyUpdater.h"
#include <algorithm>

CreepyUpdater::CreepyUpdater(CreepyInfo &creepyInfo, int baseX, double range) : creepyInfo(creepyInfo), baseX(baseX), range(range)
{
}

void CreepyUpdater::update(int elapsed)
{
    auto speed = this->creepyInfo.speed;
    if (this->creepyInfo.direction == Direction::RIGHT) {
        if (this->currentOffset < range) {
            this->currentOffset = std::min(this->currentOffset + elapsed * speed, range);
        }
        else {
            this->creepyInfo.direction = Direction::LEFT;
        }
    }
    else {
        if (this->currentOffset > -range) {
            this->currentOffset = std::max(this->currentOffset - elapsed * speed, -range);
        }
        else {
            this->creepyInfo.direction = Direction::RIGHT;
        }
    }

    auto position = this->getGameObject()->getGlobalPosition();
    position.x = (double)this->baseX + this->currentOffset;
    this->getGameObject()->setGlobalPosition(position);

}
