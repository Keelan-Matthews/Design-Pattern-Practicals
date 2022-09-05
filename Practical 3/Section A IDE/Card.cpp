#include "Card.h"


Card::Card(Confectionary *item, string message) : Decorator(item) {
    this->message = std::move(message);
    this->setPrice(25.90);
}

string Card::getDescription() {
    return item->getDescription() + "Card: \n===========================\n" + this->message + "\n===========================\n";
}

bool Card::discountable() {
    return true;
}

bool Card::isMultiple() {
    return false;
}
