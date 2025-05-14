#ifndef WORKSPACES_H
#define WORKSPACES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "workspace.h"

using namespace std;

class Workspaces {
    vector<Workspace*> workspaces;

public:
    Workspaces();
    bool load_workspaces();
    bool load_workspace(string name);
};

#endif