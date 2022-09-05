#include "Flower.h"

Flower::Flower(Confectionary *item, string variety) : Decorator(item) {
    this->variety = variety;
    this->setPrice(3.99);
}

string Flower::getDescription() {
    return item->getDescription() + "Flower: \n===========================\n" + this->variety + "\n===========================\n";
}

bool Flower::discountable() {
    return true;
}

bool Flower::isMultiple() {
    return true;
}
