#pragma once
#include "EnemyFactory.h"
class CannibalFactory : public EnemyFactory {
public:
    Enemy* createEnemy(std::string atk, std::string def) override;
};