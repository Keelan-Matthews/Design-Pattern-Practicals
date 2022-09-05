#pragma once
#include "BattleState.h"

class AgileBattleState : public BattleState {
public:
    AgileBattleState();
    int handle(string name, int dmg);
};
