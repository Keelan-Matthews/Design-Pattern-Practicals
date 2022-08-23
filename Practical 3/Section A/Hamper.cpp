#include "Hamper.h"

Hamper::Hamper(string hamperName) : Confectionary(10.0) {
    this->hamperName = hamperName;
}

Hamper::~Hamper() {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
}

void Hamper::addItem(Confectionary *item) {
    items.push_back(item);
}

void Hamper::removeItem(Confectionary *item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            items.erase(items.begin() + i);
        }
    }
}

string Hamper::getDescription() {
    string description = "";
    for (auto & item : items) {
        description += item->getDescription() + "\n";
    }
    return description;
}

double Hamper::getPrice() {
    double price = 0.0;
    for (auto & item : items) {
        price += item->getPrice();
    }
    return price;
}
