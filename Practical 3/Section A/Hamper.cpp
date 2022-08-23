#include "Hamper.h"

Hamper::Hamper(string hamperName) {
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

void Hamper::printHamper() {
    cout << "Hamper for: " << hamperName << endl;
    this->getDescription();

    double totalPrice = 0;
    for (int i = 0; i < items.size(); i++) {
        totalPrice += items[i]->getPrice();
    }
    cout << "===================================" << endl;
    cout << "Total price: " << totalPrice << endl;
    cout << "===================================" << endl;
}

string Hamper::getDescription() {
    for (auto & item : items) {
        cout << item->getDescription() << endl;
    }
}
