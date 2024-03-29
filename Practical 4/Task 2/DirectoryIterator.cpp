#include "DirectoryIterator.h"

#include <utility>

DirectoryIterator::DirectoryIterator(vector<FileComponent *> vector) {
    folders = std::move(vector);
    index = 0;
}

bool DirectoryIterator::hasNext() {
    return index < folders.size();
}

void DirectoryIterator::next() {
    index++;
}

FileComponent *DirectoryIterator::current() {
    return folders[index];
}

void DirectoryIterator::first() {
    index = 0;
}

