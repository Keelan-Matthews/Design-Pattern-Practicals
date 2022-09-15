#include <iostream>
#include <vector>
#include <string>
#include "FileComponent.h"
#include "Folder.h"
#include "NodeIterator.h"
#include "File.h"
#include "FolderObserver.h"
#include "AntiVirus.h"
#include "Caretaker.h"

using namespace std;

FileComponent* findCurrent(FileComponent *current, string dir) {
    NodeIterator *it = current->createFolderIterator();
    NodeIterator *it2 = current->createFileIterator();

    for (it->first(); it->hasNext(); it->next()) {
        if (it->current()->getName() == dir) {
            return it->current();
        }
    }

    for (it2->first(); it2->hasNext(); it2->next()) {
        if (it2->current()->getName() == dir) {
            return it2->current();
        }
    }

    return nullptr;
}

int main() {
    string path = "keelan@Keelans-Laptop: ";
    string input;
    string currentDir = "/root";

    FileComponent *root = new Folder("root");
    auto *caretaker = new Caretaker(root);
    FileComponent *home = new Folder("home");
    FileComponent *documents = new Folder("documents");

    File *poem = new File("poem.txt", "I am a file\nI'm in a directory\nI'm not a directory\nI'm a file\n");
    File *story = new File("story.txt", "Once upon a time\nThere was a file\nIt was in a directory\nIt was not a directory\n");

    root->attach(new FolderObserver(root));

    root->addDirectory(home);
    root->attach(new FolderObserver(home));

    home->addDirectory(documents);
    root->attach(new FolderObserver(documents));

    documents->addFile(poem);
    poem->attach(new AntiVirus(poem));

    documents->addFile(story);
    story->attach(new AntiVirus(story));

    FileComponent *current = root;

    while (input.substr(0, input.find(' ')) != "exit") {
        cout << "\u001b[33m" << path << "\u001b[0m\u001b[36m" << currentDir << " ~$~ \u001b[0m";
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
        } else if (input.substr(0, input.find(' ')) == "rm") {
            string dir = input.substr(input.find(' ') + 1);
            FileComponent *type = findCurrent(current, dir);

            if (type == nullptr) {
                cout << "File or directory does not exist" << endl;
            } else if (type->isFile()) {
                current->removeFile(type);
            } else {
                current->removeDirectory(type);
            }
        } else if (input.substr(0, input.find(' ')) == "print") {
            current->print();
        } else if (input.substr(0, input.find(' ')) == "copy") {
            string dir = input.substr(input.find(' ') + 1);
            FileComponent *type = findCurrent(current, dir);

            if (type == nullptr) {
                cout << "File or directory does not exist" << endl;
            } else if (type->isFile()) {
                FileComponent *clone = type->clone();
                current->addFile((File *) clone);
            } else {
                FileComponent *clone = type->clone();
                current->addDirectory((Folder *) clone);
            }
        } else if (input.substr(0, input.find(' ')) == "rename") {
            string dir = input.substr(input.find(' ') + 1, input.find_last_of(' ') - input.find(' ') - 1);
            string newName = input.substr(input.find_last_of(' ') + 1);
            FileComponent *type = findCurrent(current, dir);

            if (type == nullptr) {
                cout << "File or directory does not exist" << endl;
            }  else {
                type->setName(newName);
            }
        } else if (input.substr(0, input.find(' ')) == "backup") {
            caretaker->backup();
        } else if (input.substr(0, input.find(' ')) == "undo") {
            caretaker->undo();
        } else {
            cout << "Command not found" << endl;
        }
    }

    return 0;
}
