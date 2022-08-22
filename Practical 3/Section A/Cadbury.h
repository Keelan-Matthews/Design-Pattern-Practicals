#pragma once
#include "ConfectionaryFactory.h"

class Cadbury : public ConfectionaryFactory {
public:
    Chocolate* createChocolate(bool slab);
    AeratedChocolate* createAeratedChocolate(int bubblespccm);
};
