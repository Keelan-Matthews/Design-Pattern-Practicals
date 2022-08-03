#pragma once
#include "Enemy.h"
#include <time.h>
class EnemyFactory {
public:
    EnemyFactory(){};
    virtual ~EnemyFactory(){};
    virtual Enemy* createEnemy(std::string type) = 0;
protected:
    std::string getName() {
        std::string names[] = {"Tyson","Greg","Thomas","Kyle","Matt","Justin","Kaydyn","Tristan","Caylee","Ross","Francois","Tayla"};
        srand ( time(NULL) );
        return names[rand() % 12];
    }
};