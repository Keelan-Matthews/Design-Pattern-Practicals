#pragma once
#include "AeratedChocolate.h"

class DairyMilkBubbly : public AeratedChocolate {
public:
    explicit DairyMilkBubbly(int bubblespccm) : AeratedChocolate("Cadbury", 19.99, bubblespccm) {}
};
