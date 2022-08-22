#include "Confectionary.h"
#include "Cadbury.h"
#include "Nestle.h"
#include "Lindt.h"
#include <iostream>
using namespace std;

int main() {
    Confectionary** confectionary = new Confectionary*[3];
    ConfectionaryFactory *cadburyFactory = new Cadbury();
    ConfectionaryFactory *nestleFactory = new Nestle();
    ConfectionaryFactory *lindtFactory = new Lindt();

    ConfectionaryFactory *factories[3] = { cadburyFactory, nestleFactory, lindtFactory };

    cout << "Welcome to the Confectionary Factory! Today we will be making your own chocolates!" << endl;
    cout << "Please select a manufacturer:" << endl;
    cout << "1. Cadbury\n 2. Nestle\n 3. Lindt" << endl;
    int manufacturer;
    cin >> manufacturer;

    cout << "Please select a type of chocolate:" << endl;
    cout << "1. Bar\n 2. Aerated" << endl;
    int type;
    cin >> type;

    if (type == 1) {
        cout << "Do you want your chocolate to be a slab? (y/n)" << endl;
        char slab;
        cin >> slab;
        bool slabBool = false;
        slabBool = (slab == 'y');

        confectionary[0] = factories[manufacturer - 1]->createChocolate(slabBool);
    }
    else {
        if (type != 3) {
            cout << "How many bubbles do you want in your chocolate? (cm^3)" << endl;
            int bubbles;
            cin >> bubbles;
            confectionary[0] = factories[manufacturer - 1]->createAeratedChocolate(bubbles);
        }
        else {
            cout << "Lindt does not have an aerated chocolate" << endl;
        }
    }

    cout << "Your chocolate is: " << confectionary[0]->getDescription() << endl;

    for (int i = 0; i < sizeof(confectionary); i++) {
        delete confectionary[i];
    }

    delete[] confectionary;

    return 0;
}