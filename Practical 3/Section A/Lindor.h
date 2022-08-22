#pragma once
#include "Chocolate.h"

class Lindor : public Chocolate {
public:
    explicit Lindor(bool slab) : Chocolate("Lindt", 34.99, slab) {}
//    ~Lindor() override { cout << "Lindor destructor called" << endl; }
};
