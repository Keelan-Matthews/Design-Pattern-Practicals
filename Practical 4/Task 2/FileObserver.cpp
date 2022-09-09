#include "FileObserver.h"

FileObserver::FileObserver(FileComponent *subject) : Observer(subject) {
    this->name = subject->getName() + "-observer";
}

void FileObserver::update() {
    cout << this->name << " has been notified" << endl;
}
