/*
 *  Root.h
 *  Created on: 9/15/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once


class FileComponent;
#include <vector>
using namespace std;

class Root {
private:
    vector<FileComponent*> folderState;
    vector<FileComponent*> fileState;
public:
    Root(const vector<FileComponent*>& folderState, const vector<FileComponent*>& fileState);
    vector<FileComponent*> getFolderState();
    vector<FileComponent*> getFileState();
};
