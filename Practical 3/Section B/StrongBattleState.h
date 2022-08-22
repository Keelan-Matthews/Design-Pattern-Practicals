#pragma once
#include "BattleState.h"

class StrongBattleState : public BattleState {
    StrongBattleState();
    int handle(string name, int dmg);
};
