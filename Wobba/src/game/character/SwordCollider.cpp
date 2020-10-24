#include "SwordCollider.h"

SwordCollider::SwordCollider(CharacterInfo &characterInfo) : Collider({ 4, 1 }, { 0, 0 }, true), characterInfo(characterInfo)
{
}

Vector SwordCollider::getOffset()
{
    if (this->characterInfo.attacking) {
        if (this->characterInfo.lastMovementDirection == Direction::LEFT) {
            return { (double)-this->characterInfo.attackDuration / 100 - 2, 4 };
        }
        else {
            return { (double)this->characterInfo.attackDuration / 100 + 6, 4 };
        }
    }

    return { 4, 4 };
}
