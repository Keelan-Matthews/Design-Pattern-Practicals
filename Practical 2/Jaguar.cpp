#include "Jaguar.h"

bool Jaguar::hitSquadMember(SquadMember *z) {
    std::cout << "Jaguar leaps toward the " << z->getName() << "and deliver's a forceful " << z->getATK() << std::endl;
    return z->takeDamage(this->getDMG()) <=0;
}

void Jaguar::celebrate() {
    std::cout << "Should have fought harder soldier" << std::endl;
}

bool Jaguar::getHit(SquadMember *z) {
    std::cout << "Growls in pain as he is maimed. Jaguar turns around and delivers " << z->getATK() << " against " << z->getName() << std::endl;
    if (z->getHP() > 0)
        this->setHP(this->getHP() - z->getDamage());

    return this->getHP() <= 0;
}

void Jaguar::die() {
    std::cout << "Gives one last growl before falling over." << std::endl;
}
