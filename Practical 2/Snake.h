#pragma once
#include "Enemy.h"
class Snake : public Enemy {
public:
    bool hitSquadMember(SquadMember* z);
    void celebrate();
    bool getHit(SquadMember* z);
    void die();
};