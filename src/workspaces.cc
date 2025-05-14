#include "workspaces.h"

Workspaces::Workspaces() {
    this->load_workspaces();
}

bool Workspaces::load_workspaces() {
    cout << "Load workspaces" << endl;

    ifstream inFile("workspaces.ws");

    if (!inFile) {
        cerr << "[ERROR]: Main workspaces.ws file does not exist." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        string short_name;
        string path;

        getline(ss, name, '|');
        getline(ss, short_name, '|');
        getline(ss, path, '|');

        this->workspaces.push_back(new Workspace(name, short_name, path));
    }

    inFile.close(); 

    return true;
}

bool Workspaces::load_workspace(string name) {
    cout << "Load workspace: " << name << endl;

    for (auto& workspace : this->workspaces) {
        if(workspace->name == name || workspace->short_name == name) {
            workspace->load_init_commands(workspace->path);
            workspace->is_loaded = true;
            return true;
        }
    }

    cerr << "[ERROR]: Workspace not found." << endl;
    return false;
}