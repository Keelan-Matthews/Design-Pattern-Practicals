#pragma once


#include "ConfectionaryFactory.h"

class Nestle : public ConfectionaryFactory {
public:
    Chocolate* createChocolate(bool slab);
    AeratedChocolate* createAeratedChocolate(int bubblespccm);
};
