#include "Snake.h"

bool Snake::hitSquadMember(SquadMember *z) {
    std::cout << "Snake wraps around x and uses y" << std::endl;
    return z->takeDamage() <=0;
}

void Snake::celebrate() {
    std::cout << "Player tried strongly till the end" << std::endl;
}

bool Snake::getHit(SquadMember *z) {
    std::cout << "Slithers rapidly searching for safety and employs y" << std::endl;
    if (z->isAlive()) {
        this->setHP(this->getHP() - z->getDamage());
        return this->getHP() <= 0;
    }
}

void Snake::die() {
    std::cout << "Hisses and curls up as he is defeated" << std::endl;
}
