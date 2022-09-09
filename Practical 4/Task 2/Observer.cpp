#include "Observer.h"

Observer::Observer(FileComponent *subject) {
    this->subject = subject;
}

FileComponent *Observer::getSubject() {
    return subject;
}
