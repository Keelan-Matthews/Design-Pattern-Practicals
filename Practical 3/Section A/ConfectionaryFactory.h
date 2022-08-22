#pragma once


#include "Chocolate.h"
#include "AeratedChocolate.h"

class ConfectionaryFactory {
public:
    virtual Chocolate* createChocolate() = 0;
    virtual AeratedChocolate* createAeratedChocolate() = 0;
};
