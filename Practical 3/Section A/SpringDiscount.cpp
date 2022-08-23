#include "SpringDiscount.h"

SpringDiscount::SpringDiscount(Confectionary *item) : Discount(item) {
    this->item = item;
}

string SpringDiscount::getDescription() {
    return item->getDescription() + "\nSpring Day discount of 7%!";
}

double SpringDiscount::getPrice() {
    return item->getPrice() * 0.93;
}
