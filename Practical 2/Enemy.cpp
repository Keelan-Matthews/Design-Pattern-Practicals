#include "Enemy.h"

Enemy::Enemy(int hp, std::string atk, std::string def, int dmg, std::string name){
    this->hp = hp;
    this->atk = atk;
    this->def = def;
    this->dmg = dmg;
    this->name = name;
}

Enemy::~Enemy() = default;

void Enemy::attack(SquadMember *z) {
    while (z->getHP() > 0 && this->getHP() > 0) {
        if (this->hitSquadMember(z)) {
            z->die();
            this->celebrate();
        } else {
          if (this->getHit(z))
            this->die();
        }
    }
}

int Enemy::getHP() const {
    return this->hp;
}

std::string Enemy::getATK() {
    return this->atk;
}

std::string Enemy::getDEF() {
    return this->def;
}

int Enemy::getDMG() const {
    return this->dmg;
}

void Enemy::setHP(int hp) {
    this->hp = hp;
}

std::string Enemy::getName() const {
    return this->name;
}
