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
    void setContent(string content) override;
    void print() override;
    FileComponent* clone() override;
    void addFile(FileComponent* file) override {NULL;}
    void removeFile(FileComponent* file) override {NULL;}
    void addDirectory(FileComponent* directory) override {NULL;}
    void removeDirectory(FileComponent* directory) override {NULL;}
    bool isEmpty() override {return content.empty();}
    bool listFiles() override {return false;}
    bool listDirectories() override {return false;}
    NodeIterator* createFolderIterator() override {return nullptr;}
    NodeIterator* createFileIterator() override {return nullptr;}
    void notify() override;
    bool isFile() override {return true;}
    Root* save() override {return nullptr;}
    void restore(Root* root) override {NULL;}
};
