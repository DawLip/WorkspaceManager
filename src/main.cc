#include <iostream>
#include <unistd.h>

#include "workspaces.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cerr << "[ERROR]: No workspace specified." << endl;
        return 1;
    }

    string arg1 = argv[1];

    if(arg1.compare("WorkspaceManager") == 0) {
        while(true) {
            cout << "WorkspaceManager is running..." << endl;
            sleep(1);
        }
    }
 
    Workspaces workspaces;
    workspaces.load_workspace(argv[1]);

    return 0;
}