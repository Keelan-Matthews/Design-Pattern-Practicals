#include "Pokemon.h"
#include "NormalBattleState.h"

void Pokemon::selectBattleState(BattleState *state) {
    currentState = state;
    currentState->handle(this->name,this->dmg);
}

Pokemon::Pokemon(string name, int hp, int dmg, PlayStyle *playStyle) {
    this->name = name;
    this->hp = hp;
    this->dmg = dmg;
    this->playStyle = playStyle;
    this->currentState = new NormalBattleState();
    this->strongStateTurns = 0;
}

int Pokemon::attack() {
    if (hp > 0) {
        cout << this->name << this->playStyle->attack() << endl;
        return this->currentState->handle(this->name,this->dmg);
    }
    else {
        cout << this->name << " has fainted and cannot attack" << endl;
        return 0;
    }
}

void Pokemon::setPlayStyle(PlayStyle *playStyle) {
    this->playStyle = playStyle;
}

bool Pokemon::takeDamage(int dmg) {
    this->hp -= dmg;
    return this->hp <= 0;
}

string Pokemon::getName() {
    return this->name;
}

int Pokemon::getHp() {
    return this->hp;
}

int Pokemon::getDmg() {
    return this->dmg;
}

string Pokemon::getState() {
    return currentState->getBattleStyle();
}

string Pokemon::getPlayStyle() {
    return playStyle->getPlayStyle();
}
