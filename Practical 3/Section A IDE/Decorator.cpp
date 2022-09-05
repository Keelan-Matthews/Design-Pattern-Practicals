#include "Decorator.h"

Decorator::Decorator(Confectionary *item) : Confectionary(item->getPrice()) {
    this->item = item;
}

string Decorator::getDescription() {
    return item->getDescription();
}

double Decorator::getPrice() {
    return item->getPrice();
}
