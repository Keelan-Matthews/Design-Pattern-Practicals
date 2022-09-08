/*
 *  NodeIterator.h
 *  Created on: 9/8/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "FileComponent.h"
#include <vector>

class NodeIterator {
public:
    virtual bool hasNext() = 0;
    virtual FileComponent* next() = 0;
    virtual FileComponent* current() = 0;
    virtual void first() = 0;
};
