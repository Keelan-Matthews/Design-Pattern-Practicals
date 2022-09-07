#include "Folder.h"

#include <utility>

Folder::Folder(string name) {
    this->name = std::move(name);
}

string Folder::getName() {
    return this->name;
}

void Folder::setName(string name) {
    this->name = std::move(name);
}

void Folder::addFile(FileComponent *file) {
    this->files.push_back(file);
}

void Folder::removeFile(FileComponent *file) {
    for (int i = 0; i < this->files.size(); i++) {
        if (this->files[i] == file) {
            this->files.erase(this->files.begin() + i);
            return;
        }
    }
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
    return folder;
}
