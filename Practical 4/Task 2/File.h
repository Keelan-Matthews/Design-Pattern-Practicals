/*
 * File.cpp
 *
 *  Created on: 9/7/2022.
 *      Author: Keelan Matthews (u21549967)
 */

#pragma once

#include "FileComponent.h"

class File : public FileComponent {
private:
    string name;
    string content;
public:
    File(string name, string content);
    string getName() override;
    string getContent();
    void setName(string name) override;
    void setContent(string content);
    void print() override;
    FileComponent* clone() override;
};
