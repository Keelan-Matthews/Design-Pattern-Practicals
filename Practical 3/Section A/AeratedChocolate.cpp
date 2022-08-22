#include "AeratedChocolate.h"

AeratedChocolate::AeratedChocolate(string manufacturer, double price, int bubblespccm) : Confectionary(manufacturer, price, "Aerated") {
    this->bubblespccm = bubblespccm;
}

string AeratedChocolate::getDescription() {
    return Confectionary::getDescription() + ". " + to_string(bubblespccm) + " bubbles per cm^3";
}
