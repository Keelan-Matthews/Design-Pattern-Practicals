#pragma once


#include "Confectionary.h"
#include <vector>

class Hamper : public Confectionary {
private:
    vector<Confectionary*> items;
    string hamperName;
public:
    explicit Hamper(string hamperName);
    ~Hamper() override;
    void addItem(Confectionary* item);
    void removeItem(Confectionary* item);
    string getDescription() override;
    double getPrice() override;
    void printHamper();
};
