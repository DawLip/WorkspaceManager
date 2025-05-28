#include "workspaces.h"

Workspaces::Workspaces() {
    this->config_file = "/home/david/workspace/studies/WorkspaceManager/workspaces.ws";
    this->load_workspaces();
}

bool Workspaces::load_workspaces() {
    this->printLog("load_workspaces");

    ifstream inFile(this->config_file);

    if (!inFile) return this->printError("Main workspaces.ws file does not exist");

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
    this->printLog("load_workspace: " + name);

    for (auto& workspace : this->workspaces) {
        if(workspace->name == name || workspace->short_name == name) {
            workspace->load_init_commands(workspace->path);
            workspace->is_loaded = true;
            return true;
        }
    }

    return this->printError("Workspace "+name+" not found");
}

bool Workspaces::printError(string error_msg) {
    cerr << "[ERROR-WORKSPACES] " << error_msg << endl;
    return false;
}
bool Workspaces::printLog(string log_msg) {
    if(this->debug) cerr << "[LOG-WORKSPACES] " << log_msg << endl;
    return true;
}

bool Workspaces::add_workspaces_record(string record) {
    ofstream workspaces_file(this->config_file, ios::app);
    if (!workspaces_file) return this->printError("Main workspaces.ws file does not exist");

    workspaces_file << record << endl;
    workspaces_file.close();

    return true;
}
bool Workspaces::create_init_file() {
    string path = filesystem::current_path().string() + "/init.ws.bash";

    if(!filesystem::exists(path)) {
        ofstream create_file(path);
        if (!create_file) return this->printError("Failed to create init.ws.bash");
        create_file.close();
    }
    return true;
}

bool Workspaces::newWorkapace(string name, string short_name) {
    if(name.compare("")==0) return this->printError("Name can not be empty");

    string record = name + "|"  + short_name + "|" + filesystem::current_path().string();
    
    this->add_workspaces_record(record);
    this->create_init_file();

    return true;
}