#include "Confectionary.h"
#include <iomanip>
int Confectionary::counter = 0;

Confectionary::Confectionary(string manufacturer, double price, string type) {
    this->manufacturer = manufacturer;
    this->price = price;
    this->type = type;
    this->id = Confectionary::counter++;
}

string Confectionary::getDescription() {
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    string s = stream.str();
    return to_string(id) + ". Manufacturer: " + manufacturer + "\nType: " + type + "\nPrice: R" + s;
}

Confectionary::~Confectionary() {
    cout << "Confectionary destructor called" << endl;
}

double Confectionary::getPrice() {
    return price;
}
