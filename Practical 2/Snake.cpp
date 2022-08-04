#include "Snake.h"

bool Snake::hitSquadMember(SquadMember *z) {
    std::cout << "Snake wraps around " << z->getName() << " and uses " << this->getATK() << std::endl;
    return z->takeDamage(this->getDMG()) <=0;
}

void Snake::celebrate() {
    std::cout << "Player tried strongly till the end" << std::endl;
}

bool Snake::getHit(SquadMember *z) {
    std::cout << "Slithers rapidly searching for safety and employs " << this->getDEF() << std::endl;
    if (z->getHP() > 0)
        this->setHP(this->getHP() - z->getDamage());

    return this->getHP() <= 0;
}

void Snake::die() {
    std::cout << "Hisses and curls up as he is defeated" << std::endl;
}