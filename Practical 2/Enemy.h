#pragma once
#include <iostream>
class Enemy {
private:
    int hp;
    int atk;
    int def;
    int dmg;
public:
    Enemy();
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