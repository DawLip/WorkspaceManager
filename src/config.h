#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;

struct Config {
    string program_path = "/home/david/workspace/studies/WorkspaceManager/"; // /home/david/programs/WorkspaceManager/
    bool debug = true;
};

Config config = Config();
#endif