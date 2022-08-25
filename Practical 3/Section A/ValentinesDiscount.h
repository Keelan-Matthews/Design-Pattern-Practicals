#pragma once


#include "Decorator.h"

class ValentinesDiscount : public Decorator {
public:
    explicit ValentinesDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
