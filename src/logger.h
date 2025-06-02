#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <filesystem>

#include "config.h"

using namespace std;

class Logger {
  public:
    bool debug = config.debug;
    bool printError(string error_msg);
    bool printLog(string log_msg);
    bool printMsg(string msg);
};

#endif