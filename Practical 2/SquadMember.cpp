#include "SquadMember.h"

SquadMember::SquadMember() {

}

int SquadMember::takeDamage(int dmg) {
    this->hp -= dmg;
    return this->hp;
}

int SquadMember::getHP() const {
    return hp;
}

void SquadMember::die() {
    std::cout << "Squad member " << this->name << " died" << std::endl;
}

int SquadMember::getDamage() const {
    return dmg;
}

std::string SquadMember::getName() const {
    return name;
}

std::string SquadMember::getATK() const {
    return atk;
}

std::string SquadMember::getDEF() const {
    return def;
}

SquadMember::~SquadMember() = default;
