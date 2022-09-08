/*
 *  NodeIterator.h
 *  Created on: 9/8/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "FileComponent.h"
#include <vector>

class NodeIterator {
private:
    vector<FileComponent*> vectorContent;
    int index;
public:
    explicit NodeIterator(vector<FileComponent*> vector);
    virtual bool hasNext();
    virtual void next();
    virtual FileComponent* current();
    virtual void first();
};
