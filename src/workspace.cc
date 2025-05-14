#include "workspace.h"

Workspace::Workspace(string name, string short_name, string path) {
    this->name = name;
    this->short_name = short_name;
    this->path = path;
}

bool Workspace::load_init_commands(string path) {
    cout << "Loading init commands for workspace: " << name << endl;

    ifstream inFile(path);
    if (!inFile) {
        cerr << "[ERROR]: Main 'workspaces.ws' file does not exist." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
    }
}

void Workspace::print() {
    cout << "Name: " << name << endl;
    cout << "Short Name: " << short_name << endl;
    cout << "Path: " << path << endl;
}

bool doesFileExist(const string& filename) {
    ifstream file(filename);
    return file.good();
}