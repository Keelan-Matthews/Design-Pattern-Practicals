#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "FileComponent.h"
#include "Folder.h"
#include "DirectoryIterator.h"
#include "NodeIterator.h"
#include "File.h"
#include "FolderObserver.h"
#include "FileObserver.h"

using namespace std;

int main() {
    string path = "keelan@Keelans-Laptop";
    string input;
    string currentDir = "/root";

//    Set up a predefined directory structure
    Folder *root = new Folder("root");
    Folder *home = new Folder("home");
    Folder *documents = new Folder("documents");

    File *poem = new File("poem.txt", "I am a file\nI'm in a directory\nI'm not a directory\nI'm a file\n");
    File *story = new File("story.txt", "Once upon a time\nThere was a file\nIt was in a directory\nIt was not a directory\n");

    root->attach(new FolderObserver(root));

    root->addDirectory(home);
    root->attach(new FolderObserver(home));

    home->addDirectory(documents);
    root->attach(new FolderObserver(documents));

    documents->addFile(poem);
    root->attach(new FileObserver(poem));

    documents->addFile(story);
    root->attach(new FileObserver(story));

    Folder *current = root;

    while (input.substr(0, input.find(' ')) != "exit") {
        cout << path << currentDir << " ==> ";
        getline(cin, input);

        if (input.substr(0, input.find(' ')) == "cd") {
            string dir = input.substr(input.find(' ') + 1);

            NodeIterator *it = current->createFolderIterator();
            bool found = false;
            for (it->first(); it->hasNext(); it->next()) {
                if (it->current()->getName() == dir) {
                    current = (Folder *) it->current();
                    found = true;
                    currentDir += "/" + dir;
                    break;
                }
            }

            if (!found) cout << "Directory does not exist" << endl;
        } else if (input.substr(0, input.find(' ')) == "list") {
            cout << "Directories:" << endl;
            current->listDirectories();
            cout << "Files:" << endl;
            current->listFiles();
        } else if (input.substr(0, input.find(" ")) == "rm") {
            NodeIterator *it = current->createFolderIterator();
            NodeIterator *it2 = current->createFileIterator();
            string dir = input.substr(input.find(' ') + 1);

            bool folder = false;
            bool file = false;
            for (it->first(); it->hasNext(); it->next()) {
                if (it->current()->getName() == dir) {
                    folder = true;
                    break;
                }
            }

            if (!folder) {
                for (it2->first(); it2->hasNext(); it2->next()) {
                    if (it2->current()->getName() == dir) {
                        file = true;
                        break;
                    }
                }
            }

            if (folder) {
                current->removeDirectory(it->current());
            } else if (file) {
                current->removeFile(it2->current());
            } else {
                cout << "File or directory does not exist" << endl;
            }
        } else if (input.substr(0, input.find(" ")) == "print") {
            current->print();
        } else if (input.substr(0, input.find(" ")) == "copy") {
            NodeIterator *it = current->createFolderIterator();
            NodeIterator *it2 = current->createFileIterator();
            string dir = input.substr(input.find(' ') + 1);

            bool folder = false;
            bool file = false;
            for (it->first(); it->hasNext(); it->next()) {
                if (it->current()->getName() == dir) {
                    folder = true;
                    break;
                }
            }

            if (!folder) {
                for (it2->first(); it2->hasNext(); it2->next()) {
                    if (it2->current()->getName() == dir) {
                        file = true;
                        break;
                    }
                }
            }

            if (folder) {
                FileComponent *clone = it->current()->clone();
                current->addDirectory((Folder *) clone);
            } else if (file) {
                FileComponent *clone = it2->current()->clone();
                current->addFile((File *) clone);
            } else {
                cout << "File or directory does not exist" << endl;
            }
        } else if (input.substr(0, input.find(" ")) == "rename") {
            NodeIterator *it = current->createFolderIterator();
            NodeIterator *it2 = current->createFileIterator();
            string dir = input.substr(input.find(' ') + 1);
            string newName = input.substr(input.find_last_of(' ') + 1);

            bool folder = false;
            bool file = false;
            for (it->first(); it->hasNext(); it->next()) {
                if (it->current()->getName() == dir) {
                    folder = true;
                    break;
                }
            }

            if (!folder) {
                for (it2->first(); it2->hasNext(); it2->next()) {
                    if (it2->current()->getName() == dir) {
                        file = true;
                        break;
                    }
                }
            }

            if (folder) {
                it->current()->setName(newName);
            } else if (file) {
                it2->current()->setName(newName);
            } else {
                cout << "File or directory does not exist" << endl;
            }
        }
    }

    return 0;
}
