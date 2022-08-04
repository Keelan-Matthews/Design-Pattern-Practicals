#include "Cannibal.h"

bool Cannibal::hitSquadMember(SquadMember *z) {
    std::cout << "Cannibal rushes towards " << z->getName() << " with a " << this->getATK() << std::endl;
    return z->takeDamage(this->getDMG()) <=0;
}

void Cannibal::celebrate() {
    std::cout << "Shakes his " << this->getATK() << std::endl;
}

bool Cannibal::getHit(SquadMember *z) {
    std::cout << "The other villagers come running deploying " << this->getDEF() << std::endl;
    if (z->getHP() > 0)
        this->setHP(this->getHP() - z->getDamage());

    return this->getHP() <= 0;
}

void Cannibal::die() {
    std::cout << "Screams with his last breath, 'I am your father'" << std::endl;
}
