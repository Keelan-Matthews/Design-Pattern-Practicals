#include <sstream>
#include "FileIterator.h"

FileIterator::FileIterator(vector<FileComponent *> vector) {
    files = std::move(vector);
    index = 0;
}

bool FileIterator::hasNext() {
    return index < files.size();
}

void FileIterator::next() {
    index++;
}

FileComponent *FileIterator::current() {
    return files[index];
}

void FileIterator::first() {
    index = 0;
}
