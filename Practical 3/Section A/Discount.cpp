#include "Discount.h"

Discount::Discount(Confectionary *item) : Confectionary(item->getPrice()) {
    this->item = item;
}

string Discount::getDescription() {
    return item->getDescription();
}

double Discount::getPrice() {
    return item->getPrice();
}
