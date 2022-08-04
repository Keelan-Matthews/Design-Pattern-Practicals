#pragma once
#include <iostream>
#include "SquadMember.h"
class Enemy {
private:
    int hp;
    std::string atk;
    std::string def;
    int dmg;
    std::string name;
public:
    Enemy(int hp, std::string atk, std::string def, int dmg, std::string name);
    virtual ~Enemy();
    void attack(SquadMember* z);
    int getHP() const;
    void setHP(int hp);
    std::string getATK();
    std::string getDEF();
    int getDMG() const;
    std::string getName() const;
    virtual bool hitSquadMember(SquadMember* z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit(SquadMember* z) = 0;
    virtual void die() = 0;
};