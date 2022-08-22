#pragma once
#include "Chocolate.h"

class Lindor : public Chocolate {
public:
    explicit Lindor(bool slab) : Chocolate("Lindor", 34.99, slab) {}
};
