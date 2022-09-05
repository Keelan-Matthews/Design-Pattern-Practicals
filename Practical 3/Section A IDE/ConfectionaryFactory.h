#pragma once


#include "Chocolate.h"
#include "AeratedChocolate.h"

class ConfectionaryFactory {
public:
    virtual Chocolate* createChocolate(bool slab) = 0;
    virtual AeratedChocolate* createAeratedChocolate(int bubblespccm) { return nullptr; };
};
