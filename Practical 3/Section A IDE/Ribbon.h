#pragma once


#include "Decorator.h"

class Ribbon : public Decorator {
private:
    string color;
public:
    explicit Ribbon(Confectionary *item, string color);
    string getDescription() override;
    bool discountable() override;
    bool isMultiple() override;
};