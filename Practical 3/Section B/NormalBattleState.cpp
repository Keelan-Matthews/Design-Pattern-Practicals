#include "NormalBattleState.h"

NormalBattleState::NormalBattleState() {
    this->battleStyle = "normal";
}

int NormalBattleState::handle(string name, int dmg) {
    cout << name << " has no special battle state, normal attack will deal " << dmg << " points." << endl;
    return dmg;
}
