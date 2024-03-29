#pragma once
#include <iostream>

class SquadMember {
public:
    SquadMember();
    virtual SquadMember *clone() = 0;
    virtual ~SquadMember();
    int takeDamage(int dmg);
    int getDamage() const;
    int getHP() const;
    std::string getName() const;
    void die();
protected:
    int dmg{};
    std::string atk;
    std::string def;
    std::string name;
    int hp{};
};