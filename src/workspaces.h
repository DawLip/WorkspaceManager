#ifndef WORKSPACES_H
#define WORKSPACES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <filesystem>

#include "workspace.h"

using namespace std;

class Workspaces {
    vector<Workspace*> workspaces;
    string config_file;

    bool debug = true;

public:
    Workspaces();
    bool load_workspaces();
    bool load_workspace(string name);

    bool newWorkapace(string name, string short_name);
    bool add_workspaces_record(string record);
    bool create_init_file();

    bool printError(string error_msg);
    bool printLog(string log_msg);
};

#endif