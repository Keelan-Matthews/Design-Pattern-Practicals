#pragma once


#include "Decorator.h"

class Note : public Decorator {
private:
    string message;
public:
    explicit Note(Confectionary *item, string message);
    string getDescription() override;
    bool discountable() override;
    bool isMultiple() override;
};
