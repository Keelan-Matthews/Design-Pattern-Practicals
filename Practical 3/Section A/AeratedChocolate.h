#pragma once
#include "Confectionary.h"

class AeratedChocolate : public Confectionary {
private:
    int bubblespccm;
public:
    AeratedChocolate(string manufacturer, double price, int bubblespccm);
    string getDescription();
};
