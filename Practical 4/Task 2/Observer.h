/*
 *  Observer.h
 *  Created on: 9/9/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once

class FileComponent;
#include "FileComponent.h"

class Observer {
private:
    FileComponent* subject;
public:
    Observer(FileComponent* subject);
    virtual void update() = 0;
protected:
    FileComponent* getSubject();
};
