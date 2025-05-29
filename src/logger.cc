#include "logger.h"

bool Logger::printError(string error_msg) {
    cerr << "[ERROR-WORKSPACES] " << error_msg << endl;
    return false;
}
bool Logger::printLog(string log_msg) {
    if(this->debug) cerr << "[LOG-WORKSPACES] " << log_msg << endl;
    return true;
}
bool Logger::printMsg(string msg) {
    if(this->debug) cerr << "[WM] " << msg << endl;
    return true;
}