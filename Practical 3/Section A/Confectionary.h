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
    explicit Confectionary(double price);
    Confectionary(string manufacturer, double price, string type);
    virtual ~Confectionary() = 0;
    virtual string getDescription();
    virtual double getPrice();
    virtual void setPrice(double price);
    virtual bool discountable() { return false; };
    virtual bool isMultiple() { return false; };
};