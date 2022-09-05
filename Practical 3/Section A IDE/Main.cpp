#include "Confectionary.h"
#include "Cadbury.h"
#include "Nestle.h"
#include "Lindt.h"
#include "Hamper.h"
#include "ValentinesDiscount.h"
#include "MothersDiscount.h"
#include "SpringDiscount.h"
#include "Ribbon.h"
#include "Note.h"
#include "Card.h"
#include "Flower.h"
#include <iostream>
using namespace std;

int main() {
    ConfectionaryFactory *factories[3] = { new Cadbury(), new Nestle(), new Lindt() };

    cout << "Thank you for shopping with Lynnwood Florists, please fill in the following information\nfor your hamper:" << endl;
    cout << "What is the date? dd Month" << endl;
    string date;
    getline(cin,date);
    cout << "Who is this hamper for: ";
    string hamperName;
    cin.ignore();
    cin >> hamperName;

    cout << "How many items would you like to add to your hamper: ";
    int numItems;
    cin.ignore();
    cin >> numItems;

    Confectionary** confectionary = new Confectionary*[numItems];
    Hamper* hamper = new Hamper(hamperName);

    cout << "Please enter the following information for each item:" << endl;
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
        cout << confectionary[numItems]->getDescription() <<  "\n1x added to hamper" << endl;
        cout << "Press enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("clear");
    }

    //Applying the addon decorators to the hamper
    cout << "Select an add-on you would like: " << endl;
    cout << "1. Ribbon\n2. Note\n3. Card\n4. Flower\n5. None" << endl;
    int addon;
    cin >> addon;

    Confectionary* modHamper;

    if (addon == 1) {
        cout << "What color ribbon would you like?" << endl;
        string color;
        cin.ignore();
        cin >> color;
        modHamper = new Ribbon(hamper, color);
    }
    else if (addon == 2) {
        cout << "Please enter the message you want to include on the note:" << endl;
        string message;
        cin.ignore();
        getline(cin, message);
        modHamper = new Note(hamper, message);
    }
    else if (addon == 3) {
        cout << "Please enter the message you want to include on the card:" << endl;
        string message;
        cin.ignore();
        getline(cin, message);
        modHamper = new Card(hamper, message);
    }
    else if (addon == 4) {
        cout << "Please enter the type of flower you would like:" << endl;
        string variety;
        cin.ignore();
        getline(cin, variety);
        modHamper = new Flower(hamper, variety);
    }
    else if (addon == 5) {
        modHamper = hamper;
    }
    else {
        cout << "Invalid input" << endl;
    }

    //Applying the discount decorator to the hamper

    Confectionary* discountHamper;

    if (date == "14 February" && modHamper->discountable()) {
        discountHamper = new ValentinesDiscount(modHamper);
    }
    else if (date == "14 May" && modHamper->discountable()) {
        discountHamper = new MothersDiscount(modHamper);
    }
    else if (date == "1 September" && modHamper->discountable()) {
        discountHamper = new SpringDiscount(modHamper);
    }
    else {
        discountHamper = modHamper;
    }

    cout << "==========================================================================" << endl;
    cout << "Your items have been added, here is your hamper:" << endl;
    cout << discountHamper->getDescription() << endl;
    stringstream stream;
    stream << fixed << setprecision(2) << discountHamper->getPrice();
    string s = stream.str();
    cout << "Price: " << s << endl;
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