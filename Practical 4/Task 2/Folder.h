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
    vector<FileComponent*> folders;
public:
    explicit Folder(string name);
    string getName() override;
    void setName(string name) override;
    void addFile(FileComponent* file) override;
    void removeFile(FileComponent* file) override;
    void print() override;
    FileComponent* clone() override;
    void addDirectory(FileComponent* directory) override;
    void removeDirectory(FileComponent* directory) override;
    bool isEmpty() override;
    bool listFiles() override;
    bool listDirectories() override;
    NodeIterator* createIterator() override;
};
