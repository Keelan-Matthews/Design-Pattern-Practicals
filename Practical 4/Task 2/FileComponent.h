/*
 *  FileComponent.h
 *  Created on: 9/7/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include <string>
#include <iostream>
using namespace std;


class FileComponent {
public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual void print() = 0;
    virtual FileComponent* clone() = 0;
};
