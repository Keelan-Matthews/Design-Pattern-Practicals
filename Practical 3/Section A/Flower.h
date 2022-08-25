#pragma once


#include "Decorator.h"

class Flower : public Decorator {
private:
    string variety;
public:
    explicit Flower(Confectionary *item, string variety);
    string getDescription() override;
    bool discountable() override;
    bool isMultiple() override;
};
