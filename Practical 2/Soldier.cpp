#include "Soldier.h"

Soldier::Soldier(int hp, int dmg, std::string atk, std::string def) {
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;

    std::string names[] = {"Dhairiya", "Francois", "Tayla", "Ross", "Thomas", "Tristan", "Justin", "Kaydyn", "Caylee","Matt"};
    srand(time(nullptr));
    this->name = "Soldier " + names[rand() % 10];
}

Soldier::Soldier(const Soldier &soldier) {
    this->hp = soldier.hp;
    this->dmg = soldier.dmg;
    this->atk = soldier.atk;
    this->def = soldier.def;

    std::string names[] = {"Dhairiya", "Francois", "Tayla", "Ross", "Thomas", "Tristan", "Justin", "Kaydyn", "Caylee","Matt"};
    auto filtered = std::remove(std::begin(names), std::end(names), soldier.name);
    srand(time(nullptr));
    this->name = "Soldier " + filtered[rand() % filtered->size()];
}

SquadMember *Soldier::clone() {
    return new Soldier(*this);
}
