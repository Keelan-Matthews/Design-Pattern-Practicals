/*
 *  AntiVirus.h
 *  Created on: 9/9/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


#include "Observer.h"

class AntiVirus : public Observer {
private:
    string name;
public:
    explicit AntiVirus(FileComponent* subject);
    void update() override;
};
