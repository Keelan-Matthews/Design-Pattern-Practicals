#pragma once


#include "Discount.h"

class SpringDiscount : public Discount {
public:
    explicit SpringDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
