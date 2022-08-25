#include "Note.h"


Note::Note(Confectionary *item, string message) : Decorator(item) {
    this->message = std::move(message);
    this->setPrice(0);
}

string Note::getDescription() {
    return item->getDescription() + "Note: \n===========================\n" + this->message + "\n===========================\n";
}

bool Note::discountable() {
    return false;
}

bool Note::isMultiple() {
    return false;
}
