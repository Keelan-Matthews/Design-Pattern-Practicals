#pragma once
#include <string>
using namespace std;

class PlayStyle {
protected:
    string name;
public:
    virtual string attack() = 0;
    string getPlayStyle() { return name; }
};
