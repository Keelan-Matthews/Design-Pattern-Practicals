#pragma once
#include "Chocolate.h"

class DairyMilk : public Chocolate {
public:
    explicit DairyMilk(bool slab) : Chocolate("Cadbury", 16.99, slab) {}
};
