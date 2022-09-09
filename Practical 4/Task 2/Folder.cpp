#include "Folder.h"
#include "DirectoryIterator.h"
#include "FileIterator.h"
#include <utility>

Folder::Folder(string name) {
    this->name = std::move(name);
}

string Folder::getName() {
    return this->name;
}

void Folder::setName(string name) {
    this->name = std::move(name);
    this->notify();
}

void Folder::addFile(FileComponent *file) {
    this->files.push_back(file);
    this->notify();
}

void Folder::removeFile(FileComponent *file) {
    for (int i = 0; i < this->files.size(); i++) {
        if (this->files[i] == file) {
            this->files.erase(this->files.begin() + i);
        }
    }
    this->notify();
}

void Folder::print() {
    cout << "Folder: " << this->name << endl;
    cout << "----------------------------------" << endl;
    for (auto & file : this->files) {
        file->print();
    }
}

FileComponent *Folder::clone() {
    auto* folder = new Folder(this->name + "-copy");
    for (auto & file : this->files) {
        folder->addFile(file->clone());
    }
    this->notify();
    return folder;
}

void Folder::addDirectory(FileComponent *directory) {
    this->folders.push_back(directory);
    this->notify();
}

void Folder::removeDirectory(FileComponent *directory) {
    for (int i = 0; i < this->folders.size(); i++) {
        if (this->folders[i] == directory) {
            this->folders.erase(this->folders.begin() + i);
        }
    }
    this->notify();
}

bool Folder::isEmpty() {
    return this->folders.empty();
}

bool Folder::listFiles() {
    if (this->files.empty()) {
        cout << "No files in this folder" << endl;
        return false;
    }
    for (auto & file : this->files) {
        cout << file->getName() << endl;
    }
    return true;
}

bool Folder::listDirectories() {
    if (this->folders.empty()) {
        cout << "No folders in this folder" << endl;
        return false;
    }
    for (auto & folder : this->folders) {
        cout << folder->getName() << endl;
    }
    return true;
}

NodeIterator *Folder::createFolderIterator() {
    return new DirectoryIterator(this->folders);
}

NodeIterator *Folder::createFileIterator() {
    return new FileIterator(this->files);
}

void Folder::notify() {
    for (auto & observer : this->observers) {
        observer->update();
    }
}
