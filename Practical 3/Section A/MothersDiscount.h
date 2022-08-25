#pragma once


#include "Decorator.h"

class MothersDiscount : public Decorator {
public:
    explicit MothersDiscount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
