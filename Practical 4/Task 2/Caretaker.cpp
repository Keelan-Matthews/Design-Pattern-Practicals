#include "Caretaker.h"

Caretaker::Caretaker(FileComponent *root) {
    this->root = root;
}

void Caretaker::undo() {
    if (!state.empty()) {
        state.pop_back();
        if (!state.empty()) {
            root->restore(state.back());
        }
    }
}

void Caretaker::backup() {
    this->state.push_back(root->save());
}

void Caretaker::clean() {
    for (auto & i : state) {
        delete i;
    }
    state.clear();
}

Caretaker::~Caretaker() {
    clean();
}
