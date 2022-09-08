/*
 *  FileComponent.h
 *  Created on: 9/7/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include <string>
#include <iostream>
#include "NodeIterator.h"

using namespace std;
class NodeIterator;

class FileComponent {
public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual void setContent(string content) = 0;
    virtual void print() = 0;
    virtual FileComponent* clone() = 0;
    virtual void addFile(FileComponent* file) = 0;
    virtual void removeFile(FileComponent* file) = 0;
    virtual void addDirectory(FileComponent* directory) = 0;
    virtual void removeDirectory(FileComponent* directory) = 0;
    virtual bool isEmpty() = 0;
    virtual bool listFiles() = 0;
    virtual bool listDirectories() = 0;
    virtual NodeIterator* createFolderIterator() = 0;
    virtual NodeIterator* createFileIterator() = 0;
};
