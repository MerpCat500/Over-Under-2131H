#pragma once
#include "vex.h"
#include <string>

class TerminalLogger {
public:
  TerminalLogger() {
    Log("Init", "Terminal Init");
  }
 
  template<typename ... Strings>
  void Log(std::string Level, const Strings&... rest) {
    std::cout << "[" << Level << "] :";
    ((std::cout << " " << rest), ...);
    std::cout << "" << std::endl;
  }
};

extern TerminalLogger Terminal;
