#pragma once


#include "Discount.h"

class ValentinesDiscount : public Discount {
public:
    explicit ValentinesDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
