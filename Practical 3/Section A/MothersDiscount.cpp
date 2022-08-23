#include "MothersDiscount.h"

MothersDiscount::MothersDiscount(Confectionary *item) : Discount(item) {
    this->item = item;
}

string MothersDiscount::getDescription() {
    return item->getDescription() + "\nMothers Day discount of 3.5%!";
}

double MothersDiscount::getPrice() {
    return item->getPrice() * 0.965;
}
