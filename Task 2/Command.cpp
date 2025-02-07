#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

// Function to display files in the current directory
void displayDirectory() {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(".");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            cout << ent->d_name << endl;
        }
        closedir(dir);
    } else {
        cout << "Error opening directory" << endl;
    }
}

// Function to create a directory
void createDirectory(string dirName) {
#ifdef _WIN32
    if (mkdir(dirName.c_str()) == -1)  // Windows only requires one argument
#else
    if (mkdir(dirName.c_str(), 0777) == -1)  // Linux/macOS require two arguments
#endif
    {
        cout << "Error creating directory" << endl;
    } else {
        cout << "Directory created successfully" << endl;
    }
}


// Function to copy a file
void copyFile(string source, string destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);
    if (!src || !dest) {
        cout << "Error copying file" << endl;
        return;
    }
    dest << src.rdbuf();
    cout << "File copied successfully" << endl;
}

// Function to move a file
void moveFile(string source, string destination) {
    if (rename(source.c_str(), destination.c_str()) != 0) {
        cout << "Error moving file" << endl;
    } else {
        cout << "File moved successfully" << endl;
    }
}

int main() {
    string command;

    while (true) {
        cout << "\nEnter command (ls, mkdir, cp, mv, exit): ";
        cin >> command;
        
        if (command == "exit") {
            break;
        } else if (command == "ls") {
            displayDirectory();
        } else if (command == "mkdir") {
            string dirName;
            cout << "Enter directory name: ";
            cin >> dirName;
            createDirectory(dirName);
        } else if (command == "cp") {
            string source, destination;
            cout << "Enter source file: ";
            cin >> source;
            cout << "Enter destination file: ";
            cin >> destination;
            copyFile(source, destination);
        } else if (command == "mv") {
            string source, destination;
            cout << "Enter source file: ";
            cin >> source;
            cout << "Enter destination file: ";
            cin >> destination;
            moveFile(source, destination);
        } else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
