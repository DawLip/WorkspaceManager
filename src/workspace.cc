#include "workspace.h"

Workspace::Workspace(string name, string short_name, string path) {
    this->name = name;
    this->short_name = short_name;
    this->path = path;
}

bool Workspace::load_init_commands(string path) {
    cout << "Loading init commands for workspace: " << name << endl;

    ifstream inFile(path+"/init.ws.bash");
    if (!inFile) {
        cerr << "[ERROR]: '" << path << "/init.ws.bash' file does not exist." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) init_commands.push_back(line);
    inFile.close();

    this->execute_init_commands();

    return true;
}

void executeCMD(string cmd, string log=""){
    system(cmd.c_str());
    if(log=="") log=cmd;
    cout << "[CMD] " << log << endl;
}

bool Workspace::execute_init_commands() {
    string session_name = this->name;
    string window_name = "WorkspaceManager";
    string pane_name = "0";

    cout << "Executing init commands for workspace: " << name << endl;

    executeCMD("tmux new-session -d -s " + session_name + " -n WorkspaceManager");
    executeCMD("tmux send-keys -t "+session_name+":"+window_name+"."+pane_name+" \"wm WorkspaceManager\" C-m");

    for (const auto& command : init_commands) {
        if(command.size() >= 2 && command.substr(0, 2) == "#>") {
            stringstream ss(command);
            string prefix, operation, target;

            getline(ss, prefix, ' ');
            getline(ss, operation, ' ');
            getline(ss, target, ' ');
            
            if (operation == "window") {
                window_name = target;
                pane_name = "0";
                executeCMD("tmux new-window -t " + session_name + " -n " + window_name);
                executeCMD("tmux send-keys -t "+session_name+":"+window_name+"."+pane_name+" \""+"cd "+ this->path+"\" C-m");
            }
            else if (operation == "pane") {
                pane_name = target;
                executeCMD("tmux send-keys -t "+session_name+":"+window_name+"."+pane_name+" \""+"cd "+ this->path+"\" C-m");
            }
            else if (operation == "split") executeCMD("tmux split-window -" + target + " -t " + session_name + ":" + window_name);
            else if (operation == "cmd") executeCMD(target);
            else cerr << "[ERROR]: Unknown operation: " << operation << endl;
            
        } else executeCMD("tmux send-keys -t "+session_name+":"+window_name+"."+pane_name+" \""+command+"\" C-m");
    }

    return true;
}

void Workspace::print() {
    cout << " >>> Workspace '"<< this->name <<"' in " << this->path << endl;
    cout << "Init:" << endl;
    for (const auto& command : init_commands) {
        cout << "| " <<command << endl;
    }
}