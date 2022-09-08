/*
 *  FileIterator.h
 *  Created on: 9/8/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "NodeIterator.h"
#include "File.h"

class FileIterator : public NodeIterator {
private:
    vector<FileComponent*> files;
    int index;
public:
    explicit FileIterator(vector<FileComponent*> vector);
    bool hasNext() override;
    FileComponent* next() override;
    FileComponent* current() override;
    void first() override;
};
