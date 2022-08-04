#pragma once
#include "EnemyFactory.h"
class GorillaFactory : public EnemyFactory {
public:
    Enemy* createEnemy(std::string atk, std::string def) override;
};