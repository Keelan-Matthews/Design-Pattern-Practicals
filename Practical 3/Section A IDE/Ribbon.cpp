#include "Ribbon.h"

Ribbon::Ribbon(Confectionary *item, string color) : Decorator(item) {
    this->color = std::move(color);
    this->setPrice(7.75);
}

string Ribbon::getDescription() {
    return item->getDescription() + "Ribbon color: " + this->color;
}

bool Ribbon::discountable() {
    return false;
}

bool Ribbon::isMultiple() {
    return true;
}
