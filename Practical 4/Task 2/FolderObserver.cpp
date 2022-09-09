#include "FolderObserver.h"

FolderObserver::FolderObserver(FileComponent *subject) : Observer(subject) {
    this->name = subject->getName() + "-observer";
}

void FolderObserver::update() {
    cout << this->name << " has been notified" << endl;
}
