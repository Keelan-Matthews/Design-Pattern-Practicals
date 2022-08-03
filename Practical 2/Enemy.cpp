#include "Enemy.h"

Enemy::Enemy(int hp, std::string atk, std::string def, int dmg) {
    this->hp = hp;
    this->atk = atk;
    this->def = def;
    this->dmg = dmg;
}

Enemy::~Enemy() {}

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

int Enemy::getHP() {
    return this->hp;
}

int Enemy::getATK() {
    return this->atk;
}

int Enemy::getDEF() {
    return this->def;
}

int Enemy::getDMG() {
    return this->dmg;
}

void Enemy::setHP(int hp) {
    this->hp = hp;
}
