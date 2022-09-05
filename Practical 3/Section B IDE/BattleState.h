#pragma once
#include <string>
#include <iostream>
using namespace std;

class BattleState {
protected:
    string battleStyle;
public:
    virtual int handle(string name, int dmg) = 0;
    string getBattleStyle() { return battleStyle; }
};
