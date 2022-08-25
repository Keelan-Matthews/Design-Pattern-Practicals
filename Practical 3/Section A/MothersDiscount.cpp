#include "MothersDiscount.h"

MothersDiscount::MothersDiscount(Confectionary *item) : Decorator(item) {
    this->item = item;
}

string MothersDiscount::getDescription() {
    return item->getDescription() + "\nMothers Day discount of 3.5%!";
}

double MothersDiscount::getPrice() {
    return item->getPrice() * 0.965;
}
