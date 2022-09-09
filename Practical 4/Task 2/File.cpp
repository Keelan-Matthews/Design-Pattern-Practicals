#include "File.h"
#include "FileIterator.h"

#include <utility>

File::File(string name, string content) {
    this->name = std::move(name);
    this->content = std::move(content);
}

string File::getName() {
    return this->name;
}

string File::getContent() {
    return this->content;
}

void File::setName(string name) {
    this->name = std::move(name);
    this->notify();
}

void File::setContent(string content) {
    this->content = std::move(content);
    this->notify();
}

void File::print() {
    cout << "File: " << this->name << endl;
    cout << "Content:\n" << this->content << endl;
}

FileComponent *File::clone() {
    return new File(this->name + "-copy", this->content);
    this->notify();
}

void File::notify() {
    for (auto & observer : this->observers) {
        observer->update();
    }
}
