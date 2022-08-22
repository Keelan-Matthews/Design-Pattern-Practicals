#include "Chocolate.h"

Chocolate::Chocolate(string manufacturer, double price, bool slab) : Confectionary(manufacturer, price, "Bar") {
    this->slab = slab;
}

string Chocolate::getDescription() {
    return Confectionary::getDescription() + " " + (slab ? " - slab" : " - mini bar");
}
