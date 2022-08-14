#include "Soldier.h"
#include <vector>
#include <algorithm>

std::vector<std::string> soldierNames = {"Kirthen", "Taralen", "Labyrin", "Moonbow", "Erevand", "Aerdrie", "Demiwel", "Faenyan", "Crealln","Raphael"};

Soldier::Soldier(int hp, int dmg, std::string atk, std::string def) {
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;

    this->name = "Soldier " + soldierNames[rand() % soldierNames.size()];
}

Soldier::Soldier(const Soldier &soldier) {
    this->hp = soldier.hp;
    this->dmg = soldier.dmg;
    this->atk = soldier.atk;
    this->def = soldier.def;

    //Don't use already chosen name
    std::string currName = soldier.name.substr(soldier.name.find(' ') + 1);

    soldierNames.erase(std::remove(soldierNames.begin(),soldierNames.end(),currName), soldierNames.end());

    this->name = "Soldier " + soldierNames[rand() % soldierNames.size()];
}

SquadMember *Soldier::clone() {
    return new Soldier(*this);
}
