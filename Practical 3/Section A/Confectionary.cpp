#include "Confectionary.h"

Confectionary::Confectionary(string manufacturer, double price, string type) {
    this->manufacturer = manufacturer;
    this->price = price;
    this->type = type;
    this->id = Confectionary::counter++;
}

string Confectionary::getDescription() {
    return "Confectionary " + to_string(id) + ": " + manufacturer + ". " + type + ", price: R" + to_string(price);
}
