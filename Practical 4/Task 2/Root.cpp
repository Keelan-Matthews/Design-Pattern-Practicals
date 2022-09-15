#include "Root.h"

Root::Root(const vector<FileComponent *>& folderState, const vector<FileComponent *>& fileState) {
    for (auto & i : folderState) {
        this->folderState.push_back(i);
    }
    for (auto & i : fileState) {
        this->fileState.push_back(i);
    }
}

vector<FileComponent *> Root::getFolderState() {
    return folderState;
}

vector<FileComponent *> Root::getFileState() {
    return fileState;
}
