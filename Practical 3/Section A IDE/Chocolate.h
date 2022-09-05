#pragma once
#include "Confectionary.h"

class Chocolate : public Confectionary {
private:
    bool slab;
public:
    Chocolate(string manufacturer, double price, bool slab);
    ~Chocolate() override;
    string getDescription();
};
