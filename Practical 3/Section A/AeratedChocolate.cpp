#include "AeratedChocolate.h"

AeratedChocolate::AeratedChocolate(string manufacturer, double price, int bubblespccm) : Confectionary(manufacturer, price, "Aerated") {
    this->bubblespccm = bubblespccm;
}

string AeratedChocolate::getDescription() {
    return Confectionary::getDescription() + "\n" + to_string(bubblespccm) + " bubbles per cm^3";
}

AeratedChocolate::~AeratedChocolate() {
    cout << "AeratedChocolate destructor called" << endl;
}
