/*
 * Folder.cpp
 *
 *  Created on: 9/7/2022.
 *      Author: Keelan Matthews (u21549967)
 */

#pragma once
#include <vector>
#include "FileComponent.h"

class Folder : public FileComponent {
private:
    string name;
    vector<FileComponent*> files;
public:
    explicit Folder(string name);
    string getName() override;
    void setName(string name) override;
    void addFile(FileComponent* file);
    void removeFile(FileComponent* file);
    void print() override;
    FileComponent* clone() override;
};
