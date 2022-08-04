#pragma once
#include "Enemy.h"
#include <ctime>
class EnemyFactory {
public:
    EnemyFactory(){};
    virtual ~EnemyFactory(){};
    virtual Enemy* createEnemy(std::string type) = 0;
protected:
    std::string getName() {
        std::string names[] = {"Jaguar","Snake","Cannibal","Gorilla"};
        srand ( time(nullptr) );
        return names[rand() % 4];
    }
};