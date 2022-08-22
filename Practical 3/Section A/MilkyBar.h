#pragma once
#include "Chocolate.h"

class MilkyBar : public Chocolate {
public:
    explicit MilkyBar(bool slab) : Chocolate("Nestle", 14.99, slab) {}
//    ~MilkyBar() override { cout << "MilkyBar destructor called" << endl; }
};
