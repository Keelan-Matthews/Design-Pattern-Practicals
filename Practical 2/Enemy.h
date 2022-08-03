#pragma once
#include <iostream>
#include "SquadMember.h"
class Enemy {
private:
    int hp;
    std::string atk;
    std::string def;
    int dmg;
public:
    Enemy(int hp, std::string atk, std::string def, int dmg);
    ~Enemy();
    void attack(SquadMember* z);
    int getHP();
    void setHP(int hp);
    int getATK();
    int getDEF();
    int getDMG();
    virtual bool hitSquadMember(SquadMember* z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit(SquadMember* z) = 0;
    virtual void die() = 0;
};