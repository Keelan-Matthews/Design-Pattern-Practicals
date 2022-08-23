#pragma once


#include "Discount.h"

class MothersDiscount : public Discount {
public:
    explicit MothersDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
