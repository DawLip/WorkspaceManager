#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

#include "logger.h"

using namespace std;

class Workspace : public Logger {
public:
    string name;
    string short_name;
    string path;
    bool is_imported = false;
    bool is_loaded = false;
    vector<string> init_commands;

    Workspace(string name, string short_name, string path);
    bool load_init_commands(string path);
    bool execute_init_commands();
    void print();
    void executeCMD(string cmd, string log="");
};

#endif