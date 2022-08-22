#pragma once
#include "BattleState.h"

class AgileBattleState : public BattleState {
    AgileBattleState();
    int handle(string name, int dmg);
};
