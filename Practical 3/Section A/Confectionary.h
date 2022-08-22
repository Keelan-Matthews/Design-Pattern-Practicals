#pragma once
#include <string>
using namespace std;


class Confectionary {
private:
    string manufacturer;
    double price;
    string type;
    static int counter;
    int id;
public:
    Confectionary(string manufacturer, double price, string type);
    virtual string getDescription();
};