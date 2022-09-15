#include "AntiVirus.h"

AntiVirus::AntiVirus(FileComponent *subject) : Observer(subject) {
    this->name = "AntiVirus";
}

void AntiVirus::update() {
    cout << this->name << " has been notified" << endl;

    // Check if the file is infected
    if (this->getSubject()->getName() == "virus.txt") {
        cout << "The file is infected" << endl;
    }
}
