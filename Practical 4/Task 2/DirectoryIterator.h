/*
 *  DirectoryIterator.h
 *  Created on: 9/8/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "NodeIterator.h"

class DirectoryIterator : public NodeIterator {
public:
    DirectoryIterator();
    bool hasNext() override;
    void next() override;
    FileComponent* current() override;
    void first() override;
};
