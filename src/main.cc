#include <iostream>
#include <unistd.h>
#include "config.h"

#include "workspaces.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cerr << "[ERROR]: No workspace specified." << endl;
        return 1;
    }

    string arg1 = string(argv[1]);
    Workspaces workspaces;

    if(arg1.compare("new") == 0) workspaces.newWorkapace(argv[2], argv[3]);
    else if(arg1.compare("update") == 0) workspaces.updateWorkapace(argv[2], argv[3], argv[4]);
    else if(arg1.compare("remove") == 0) workspaces.removeWorkapace(argv[2]);
    else workspaces.load_workspace(argv[1]);

    return 0;
}