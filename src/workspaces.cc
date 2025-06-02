#include "workspaces.h"
#include "config.h"

Workspaces::Workspaces() {
    this->load_workspaces();
}

bool Workspaces::load_workspaces() {
    printLog("load_workspaces");

    ifstream inFile(this->program_path + "workspaces.ws");

    if (!inFile) return printError("Main workspaces.ws file does not exist");

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
    printLog("load_workspace: " + name);

    for (auto& workspace : this->workspaces) {
        if(workspace->name == name || workspace->short_name == name) {
            workspace->load_init_commands(workspace->path);
            workspace->is_loaded = true;
            return true;
        }
    }

    return printError("Workspace "+name+" not found");
}

bool Workspaces::add_workspaces_record(string record) {
    ofstream workspaces_file(this->program_path + "workspaces.ws", ios::app);
    if (!workspaces_file) return printError("Main workspaces.ws file does not exist");

    workspaces_file << record << endl;
    workspaces_file.close();

    return true;
}
bool Workspaces::create_init_file() {
    string path = filesystem::current_path().string() + "/init.ws.bash";

    if(!filesystem::exists(path)) {
        ofstream create_file(path);
        if (!create_file) return printError("Failed to create init.ws.bash");
        create_file.close();
    }
    return true;
}

bool Workspaces::newWorkapace(string name, string short_name) {
    if(name.compare("")==0) return printError("Name can not be empty");

    string record = name + "|"  + short_name + "|" + filesystem::current_path().string();
    
    this->add_workspaces_record(record);
    this->create_init_file();

    return true;
}

bool Workspaces::updateWorkapace(string ws_name, string ws_property, string value) {
    if(ws_name.compare("")==0) return printError("'ws_name' can not be empty");
    if(ws_property.compare("")==0) return printError("'ws_property' can not be empty");
    if(value.compare("")==0) return printError("'value' can not be empty");
    
    for (auto& workspace : this->workspaces) {
        if(workspace->name == ws_name || workspace->short_name == ws_name) {
            if (ws_property.compare("name")==0) workspace->name = value;
            if (ws_property.compare("short_name")==0) workspace->short_name = value;
            if (ws_property.compare("path")==0) workspace->path = value;

            ofstream file(this->program_path + "workspaces.ws", ios::trunc); 
            file.close();
            
            for (auto& ws : this->workspaces) {
                string record = ws->name + "|"  + ws->short_name + "|" + ws->path;
                this->add_workspaces_record(record);
            }

            
            return true;
        }
    }

    return printError("[ERROR] Workspace "+ws_name+" not found");
}

bool Workspaces::removeWorkapace(string ws_name) {
    if(ws_name.compare("") == 0) return printError("'ws_name' can not be empty");

    for (auto it = this->workspaces.begin(); it != this->workspaces.end(); ++it) {
        if((*it)->name == ws_name || (*it)->short_name == ws_name) {
            this->workspaces.erase(it);

            ofstream file(this->program_path + "workspaces.ws", ios::trunc);
            file.close();

            for (auto& ws : this->workspaces) {
                string record = ws->name + "|" + ws->short_name + "|" + ws->path;
                this->add_workspaces_record(record);
            }

            return true;
        }
    }
    return false;
}