#include "StrongBattleState.h"

StrongBattleState::StrongBattleState() {
    this->battleStyle = "strong";
}

int StrongBattleState::handle(string name, int dmg) {
    cout << name << " has selected a strong battle state, and will inflict " << dmg << " points on the next battle attack but misses the following attack turn." << endl;
    return 2*dmg;
}
