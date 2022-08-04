#pragma once
#include "EnemyFactory.h"
class SnakeFactory : public EnemyFactory {
public:
    Enemy* createEnemy(std::string atk, std::string def);
};