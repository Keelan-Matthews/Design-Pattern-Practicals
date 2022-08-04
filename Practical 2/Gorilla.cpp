#include "Gorilla.h"

bool Gorilla::hitSquadMember(SquadMember *z) {
    std::cout << "Gorilla slams his fists on the ground, growls and hits " << z->getName() << " with " << z->getATK() << std::endl;
    return z->takeDamage(this->getDMG()) <=0;
}

void Gorilla::celebrate() {
    std::cout << "Player tried in vain trying to save himself" << std::endl;
}

bool Gorilla::getHit(SquadMember *z) {
    std::cout << "Roars and hits his chest in anger" << std::endl;
    if (z->getHP() > 0)
        this->setHP(this->getHP() - z->getDamage());

    return this->getHP() <= 0;
}

void Gorilla::die() {
    std::cout << "The earth shakes as the gorilla falls to the ground" << std::endl;
}
