/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\merpl                                            */
/*    Created:      Wed May 31 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

TerminalLogger Terminal = TerminalLogger();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Terminal.Log("Start", "Main Started");
  vexcodeInit();

  while (true) {
    wait(20, msec);
  }
}
