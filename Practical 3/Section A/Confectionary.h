#pragma once
#include <string>
#include <iostream>
using namespace std;

class Confectionary {
private:
    string manufacturer;
    double price;
    string type;
    static int counter;
    int id;
public:
    Confectionary() = default;
    Confectionary(string manufacturer, double price, string type);
    virtual ~Confectionary() = 0;
    virtual string getDescription();
    virtual double getPrice();
};