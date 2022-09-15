/*
 *  Caretaker.h
 *  Created on: 9/15/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "FileComponent.h"

class Caretaker {
private:
    vector<Root*> state;
    FileComponent* root;
public:
    explicit Caretaker(FileComponent* root);
    ~Caretaker();
    void undo();
    void backup();
    void clean();
};
