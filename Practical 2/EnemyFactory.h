#pragma once
#include "Enemy.h"
#include <ctime>
class EnemyFactory {
public:
    EnemyFactory()= default;
    virtual ~EnemyFactory()= default;
    virtual Enemy* createEnemy(std::string atk, std::string def) = 0;
protected:
    std::string getName() {
        std::string names[] = {"I","II","III","IV", "V", "VI", "XIII", "XIX", "MXI", "XVI"};
        srand ( time(nullptr) );
        return names[rand() % 10];
    }
};