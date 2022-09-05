#pragma once
#include <sstream>
#include <iomanip>

#include "Confectionary.h"

class Decorator : public Confectionary {
protected:
    Confectionary *item;
public:
    explicit Decorator(Confectionary *item);
    string getDescription() override;
    double getPrice() override;
};
