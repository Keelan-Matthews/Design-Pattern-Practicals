#pragma once
#include <string>
#include "BattleState.h"
#include "PlayStyle.h"
using namespace std;


class Pokemon {
private:
    string name;
    int hp;
    int dmg;
    BattleState* currentState;
    PlayStyle* playStyle;
public:
    Pokemon(string name, int hp, int dmg, PlayStyle* playStyle);
    int attack();
    void setPlayStyle(PlayStyle* playStyle);
    bool takeDamage(int dmg);
    void selectBattleState(BattleState* state);
    string getName();
    int getHp();
    int getDmg();
    string getState();
    string getPlayStyle();
};
