
#include "NodeIterator.h"

#include <utility>

NodeIterator::NodeIterator(vector<FileComponent *> vector) {
    vectorContent = std::move(vector);
    index = 0;
}

bool NodeIterator::hasNext() {
    return index < vectorContent.size();
}

void NodeIterator::next() {
    index++;
}

FileComponent *NodeIterator::current() {
    return vectorContent[index];
}

void NodeIterator::first() {
    index = 0;
}
