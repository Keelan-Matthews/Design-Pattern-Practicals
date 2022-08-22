#pragma once
#include "AeratedChocolate.h"

class Aero : public AeratedChocolate {
public:
    explicit Aero(int bubblespccm) : AeratedChocolate("Aero", 21.99, bubblespccm) {}
};
