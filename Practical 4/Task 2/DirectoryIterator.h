/*
 *  DirectoryIterator.h
 *  Created on: 9/8/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "NodeIterator.h"

class DirectoryIterator : public NodeIterator {
private:
    vector<FileComponent*> folders;
    int index;
public:
    explicit DirectoryIterator(vector<FileComponent*> vector);
    bool hasNext() override;
    void next() override;
    FileComponent* current() override;
    void first() override;
};
