#include <iostream>

#include "workspaces.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cerr << "[ERROR]: No workspace specified." << endl;
        return 1;
    }
    if(argc > 2) {
        cerr << "[ERROR]: Too many arguments." << endl;
        return 1;
    }

    string workspaceToLoad = argv[1];    
    Workspaces workspaces;
    workspaces.load_workspace(workspaceToLoad);

    return 0;
}