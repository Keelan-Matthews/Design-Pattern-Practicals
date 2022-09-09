/*
 *  FolderObserver.h
 *  Created on: 9/9/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "Observer.h"

class FolderObserver : public Observer {
private:
    string name;
public:
    explicit FolderObserver(FileComponent* subject);
    void update() override;
};

