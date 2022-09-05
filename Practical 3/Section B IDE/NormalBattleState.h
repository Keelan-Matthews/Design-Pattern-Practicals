#pragma once
#include "BattleState.h"

class NormalBattleState : public BattleState {
public:
    NormalBattleState();
    int handle(string name, int dmg);
};
