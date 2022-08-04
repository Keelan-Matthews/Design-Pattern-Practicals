#pragma once
#include "EnemyFactory.h"
class JaguarFactory : public EnemyFactory {
public:
    Enemy* createEnemy(std::string atk, std::string def) override;
};