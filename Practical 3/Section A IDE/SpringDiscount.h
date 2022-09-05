#pragma once


#include "Decorator.h"

class SpringDiscount : public Decorator {
public:
    explicit SpringDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
