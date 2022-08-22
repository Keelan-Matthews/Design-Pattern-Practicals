#include "AgileBattleState.h"

AgileBattleState::AgileBattleState() {
    this->battleStyle = "agile";
}

int AgileBattleState::handle(string name, int dmg) {
    cout << name << " has selected an agile battle state, and is allowed two battle attacks in one turn and will deal " << dmg << " points." << endl;
    return (3/4)*dmg;
}
