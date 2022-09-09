/*
 *  FileObserver.h
 *  Created on: 9/9/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "Observer.h"

class FileObserver : public Observer {
private:
    string name;
public:
    explicit FileObserver(FileComponent* subject);
    void update() override;
};
