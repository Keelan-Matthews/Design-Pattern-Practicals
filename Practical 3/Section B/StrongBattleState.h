#pragma once
#include "BattleState.h"

class StrongBattleState : public BattleState {
public:
    StrongBattleState();
    int handle(string name, int dmg);
};
