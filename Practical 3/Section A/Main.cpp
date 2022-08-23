#include "Confectionary.h"
#include "Cadbury.h"
#include "Nestle.h"
#include "Lindt.h"
#include "Hamper.h"
#include <iostream>
using namespace std;

int main() {
    ConfectionaryFactory *cadburyFactory = new Cadbury();
    ConfectionaryFactory *nestleFactory = new Nestle();
    ConfectionaryFactory *lindtFactory = new Lindt();

    ConfectionaryFactory *factories[3] = { cadburyFactory, nestleFactory, lindtFactory };

    cout << "Thank you for shopping with Lynnwood Florists, please fill in the following information\nfor your hamper:" << endl;
    cout << "Who is this hamper for: ";
    string hamperName;
    cin >> hamperName;
    cout << "\nHow many items would you like to add to your hamper: ";
    int numItems;
    cin >> numItems;

    Confectionary** confectionary = new Confectionary*[numItems];
    Hamper* hamper = new Hamper(hamperName);

    cout << "\nPlease enter the following information for each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        cout << "Manufacturer:" << endl;
        cout << "1. Cadbury\n2. Nestle\n3. Lindt" << endl;
        int manufacturer;
        cin >> manufacturer;

        int type;
        if (manufacturer == 3)
            type = 1;
        else {
            cout << "Type of chocolate:" << endl;
            cout << "1. Bar\n2. Aerated" << endl;
            cin >> type;
        }

        if (type == 1) {
            cout << "Do you want your chocolate to be a slab? (y/n)" << endl;
            char slab;
            cin >> slab;
            bool slabBool = false;
            slabBool = (slab == 'y');

            confectionary[numItems] = factories[manufacturer - 1]->createChocolate(slabBool);
        }
        else {
            cout << "How many bubbles do you want in your chocolate? (cm^3)" << endl;
            int bubbles;
            cin >> bubbles;
            confectionary[numItems] = factories[manufacturer - 1]->createAeratedChocolate(bubbles);
        }

        hamper->addItem(confectionary[numItems]);
        cout << "Item " << i + 1 << ":\n" << confectionary[numItems]->getDescription() <<  "\n1x added to hamper" << endl;
        cout << "Press enter to continue..." << endl;
        cin.ignore();
        system("clear");
    }

    cout << "==========================================================================" << endl;
    cout << "Your items have been added, here is your hamper:" << endl;
    hamper->printHamper();
    cout << "==========================================================================" << endl;

    cout << "Come again soon!" << endl;
    for (int i = 0; i < sizeof(confectionary); i++) {
        if (confectionary[i] != nullptr) {
            delete confectionary[i];
        }
    }

    delete[] confectionary;
    delete hamper;

    return 0;
}