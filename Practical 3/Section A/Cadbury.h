#pragma once
#include "ConfectionaryFactory.h"

class Cadbury : public ConfectionaryFactory {
public:
    Chocolate* createChocolate(bool slab) override;
    AeratedChocolate* createAeratedChocolate(int bubblespccm) override;
};
