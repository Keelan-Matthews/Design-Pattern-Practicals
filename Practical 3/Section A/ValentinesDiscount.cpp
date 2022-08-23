#include "ValentinesDiscount.h"

ValentinesDiscount::ValentinesDiscount(Confectionary *item) : Discount(item) {
    this->item = item;
}

string ValentinesDiscount::getDescription() {
    return item->getDescription() + "\nValentines Day discount of 5%!";
}

double ValentinesDiscount::getPrice() {
    return item->getPrice() * 0.95;
}
