#pragma once
#include "SquadMember.h"
class Soldier : public SquadMember {
public:
    Soldier(int hp, int dmg, std::string atk, std::string def);
    Soldier(Soldier const &soldier);
    SquadMember *clone() override;
private:
    int dmg;
    std::string atk;
    std::string def;
    std::string name;
    int hp;
};