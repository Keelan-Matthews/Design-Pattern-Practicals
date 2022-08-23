#pragma once
#include <sstream>
#include <iomanip>

#include "Confectionary.h"

class Discount : public Confectionary {
protected:
    Confectionary *item;
public:
    explicit Discount(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
