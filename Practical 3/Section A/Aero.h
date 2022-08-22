#pragma once
#include "AeratedChocolate.h"

class Aero : public AeratedChocolate {
public:
    explicit Aero(int bubblespccm) : AeratedChocolate("Aero", 21.99, bubblespccm) {}
//    ~Aero() override { cout << "Aero destructor called" << endl; }
};
