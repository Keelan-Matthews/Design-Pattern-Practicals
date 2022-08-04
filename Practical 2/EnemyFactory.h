#pragma once
#include "Enemy.h"
#include <ctime>
class EnemyFactory {
public:
    EnemyFactory(){};
    virtual ~EnemyFactory(){};
    virtual Enemy* createEnemy(std::string atk, std::string def) = 0;
protected:
    std::string getName() {
        std::string names[] = {"Dhairiya","Francois","Tayla","Ross", "Thomas", "Tristan", "Justin", "Kaydyn", "Caylee", "Matt"};
        srand ( time(nullptr) );
        return names[rand() % 10];
    }
};