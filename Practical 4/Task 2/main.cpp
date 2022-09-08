#include <iostream>
#include <vector>
#include <string>
#include "FileComponent.h"
#include "Folder.h"
#include "DirectoryIterator.h"
#include "NodeIterator.h"
#include "File.h"
using namespace std;

int main() {
    string path = "keelan@Keelans-Laptop";
    string input;
    string commands = {"cd, list, exit, rm"};
    string currentDir = "/root";

//    Set up a predefined directory structure
    Folder *root = new Folder("root");
    Folder *home = new Folder("home");
    Folder *documents = new Folder("documents");

    File *poem = new File("poem.txt", "I am a file\nI'm in a directory\nI'm not a directory\nI'm a file\n");
    File *story = new File("story.txt", "Once upon a time\nThere was a file\nIt was in a directory\nIt was not a directory\n");

    root->addDirectory(home);
    home->addDirectory(documents);
    documents->addFile(poem);
    documents->addFile(story);

    Folder *current = root;

//    If the letters before the first space in input are in the commands array
    while (input.substr(0, input.find(' ')) != "exit") {
        cout << path << currentDir << " ==> ";
        getline(cin, input);
        cin.ignore();

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
            while (it->hasNext()) {
                cout << it->next()->getName() << endl;
            }
            while (it2->hasNext()) {
                cout << it2->next()->getName() << endl;
            }
        }
//        } else if (input.substr(0, input.find(" ")) == "rm") {
//            while (it->hasNext()) {
//                if (it->next()->getName() == input.substr(input.find(" ") + 1)) {
//                    current->removeDirectory(it->next());
//                }
//            }
//            while (it2->hasNext()) {
//                if (it2->next()->getName() == input.substr(input.find(" ") + 1)) {
//                    current->removeFile(it2->next());
//                }
//            }
//        }
    }

    return 0;
}
