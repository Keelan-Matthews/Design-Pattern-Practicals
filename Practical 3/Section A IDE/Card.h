#pragma once


#include "Decorator.h"

class Card : public Decorator {
private:
    string message;
public:
    explicit Card(Confectionary *item, string message);
    string getDescription() override;
    bool discountable() override;
    bool isMultiple() override;
};
