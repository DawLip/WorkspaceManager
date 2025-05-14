#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Workspace {
public:
    string name;
    string short_name;
    string path;
    bool is_imported = false;
    bool is_loaded = false;

    Workspace(string name, string short_name, string path);
    bool load_init_commands(string path);
    void print();
};

#endif