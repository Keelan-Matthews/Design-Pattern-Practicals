#pragma once
#include <iostream>
class SquadMember {
public:
    SquadMember();
    int takeDamage(int dmg);
    int getDamage() const;
    int getHP() const;
    std::string getATK() const;
    std::string getDEF() const;
    std::string getName() const;
    void die();
private:
    int hp;
    int dmg;
    std::string atk;
    std::string def;
    std::string name;
};