#pragma once
#include "Enemy.h"
class Snake : public Enemy {
public:
    bool hitSquadMember(SquadMember* z) override;
    void celebrate() override;
    bool getHit(SquadMember* z) override;
    void die() override;
};