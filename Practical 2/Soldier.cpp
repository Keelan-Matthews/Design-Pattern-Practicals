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

    //Don't use already chosen name
    std::string currName = soldier.name.substr(soldier.name.find(" ") + 1);

    int pos = 0;
    while (names[pos] != currName) pos++;

    for (int i = pos; i < 8; ++i)
        names[i] = names[i + 1];

    srand(time(nullptr));
    this->name = "Soldier " + names[rand() % names->size()];
}

SquadMember *Soldier::clone() {
    return new Soldier(*this);
}
