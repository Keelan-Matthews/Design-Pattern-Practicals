#pragma once


#include "ConfectionaryFactory.h"

class Lindt : public ConfectionaryFactory {
public:
    Chocolate* createChocolate(bool slab) override;
};
