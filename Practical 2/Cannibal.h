#pragma once
#include "Enemy.h"
class Cannibal : public Enemy {
public:
    using Enemy::Enemy;
    bool hitSquadMember(SquadMember* z) override;
    void celebrate() override;
    bool getHit(SquadMember* z) override;
    void die() override;
};